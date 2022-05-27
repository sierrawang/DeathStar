#include <signal.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>

#include "../utils.h"
#include "../utils_thrift.h"
#include "UserHandler.h"

using apache::thrift::protocol::TBinaryProtocolFactory;
using apache::thrift::server::TThreadedServer;
using apache::thrift::transport::TFramedTransportFactory;
using apache::thrift::transport::TServerSocket;
using namespace social_network;

void sigintHandler(int sig) { exit(EXIT_SUCCESS); }

int main(int argc, char *argv[]) {
  signal(SIGINT, sigintHandler);
  init_logger();

  SetUpTracer("config/jaeger-config.yml", "user-service");

  json config_json;
  if (load_config_file("config/service-config.json", &config_json) != 0) {
    exit(EXIT_FAILURE);
  }

  std::string secret = config_json["secret"];

  int port = config_json["user-service"]["port"];

  std::string social_graph_addr = config_json["social-graph-service"]["addr"];
  int social_graph_port = config_json["social-graph-service"]["port"];
  int social_graph_conns = config_json["social-graph-service"]["connections"];
  int social_graph_timeout = config_json["social-graph-service"]["timeout_ms"];
  int social_graph_keepalive =
      config_json["social-graph-service"]["keepalive_ms"];

  std::string user_storage_addr = config_json["user-storage-service"]["addr"];
  int user_storage_port = config_json["user-storage-service"]["port"];
  int user_storage_conns = config_json["user-storage-service"]["connections"];
  int user_storage_timeout = config_json["user-storage-service"]["timeout_ms"];
  int user_storage_keepalive =
      config_json["user-storage-service"]["keepalive_ms"];

  std::string netif = config_json["user-service"]["netif"];
  std::string machine_id = GetMachineId(netif);
  if (machine_id == "") {
    exit(EXIT_FAILURE);
  }
  LOG(info) << "machine_id = " << machine_id;

  std::mutex thread_lock;

  ClientPool<ThriftClient<SocialGraphServiceClient>> social_graph_client_pool(
      "social-graph", social_graph_addr, social_graph_port, 0,
      social_graph_conns, social_graph_timeout, social_graph_keepalive, config_json);

  ClientPool<ThriftClient<UserStorageServiceClient>> user_storage_client_pool(
      "user-storage", user_storage_addr, user_storage_port, 0,
      user_storage_conns, user_storage_timeout, user_storage_keepalive, config_json);

  std::shared_ptr<TServerSocket> server_socket = get_server_socket(config_json, "0.0.0.0", port);

  TThreadedServer server(
      std::make_shared<UserServiceProcessor>(std::make_shared<UserHandler>(
          &thread_lock, machine_id, secret, &user_storage_client_pool,
          &social_graph_client_pool)),
      server_socket,
      std::make_shared<TFramedTransportFactory>(),
      std::make_shared<TBinaryProtocolFactory>());
  LOG(info) << "Starting the user-service server ...";
  server.serve();
}
