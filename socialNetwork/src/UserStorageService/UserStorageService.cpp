#include <signal.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TTransport.h>
#include <thrift/transport/TServerSocket.h>

#include "../utils.h"
#include "../utils_thrift.h"
#include "UserStorageHandler.h"

using apache::thrift::protocol::TBinaryProtocolFactory;
using apache::thrift::server::TThreadedServer;
using apache::thrift::transport::TTransportFactory;
using apache::thrift::transport::TServerSocket;
using namespace social_network;

void sigintHandler(int sig) { exit(EXIT_SUCCESS); }

int main(int argc, char *argv[]) {
  signal(SIGINT, sigintHandler);
  init_logger();
  SetUpTracer("config/jaeger-config.yml", "user-storage-service");
  json config_json;
  if (load_config_file("config/service-config.json", &config_json) != 0) {
    exit(EXIT_FAILURE);
  }

  int port = config_json["user-storage-service"]["port"];
  std::shared_ptr<TServerSocket> server_socket = get_server_socket(config_json, "0.0.0.0", port);

  TThreadedServer server(
      std::make_shared<UserStorageServiceProcessor>(std::make_shared<UserStorageHandler>()),
      server_socket,
      std::make_shared<TTransportFactory>(),
      std::make_shared<TBinaryProtocolFactory>());

  LOG(info) << "Starting the user-storage-service server...";
  server.serve();
}
