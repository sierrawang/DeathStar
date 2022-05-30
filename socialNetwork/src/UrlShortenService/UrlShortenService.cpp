#include <signal.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>

#include "../utils.h"
// #include "../utils_memcached.h"
// #include "../utils_mongodb.h"
#include "../utils_thrift.h"
#include "UrlShortenHandler.h"
#include "nlohmann/json.hpp"

using apache::thrift::protocol::TBinaryProtocolFactory;
using apache::thrift::server::TThreadedServer;
using apache::thrift::transport::TFramedTransportFactory;
using apache::thrift::transport::TServerSocket;
using namespace social_network;

// static memcached_pool_st* memcached_client_pool;
// static mongoc_client_pool_t* mongodb_client_pool;

void sigintHandler(int sig) {
  // if (memcached_client_pool != nullptr) {
  //   memcached_pool_destroy(memcached_client_pool);
  // }
  // if (mongodb_client_pool != nullptr) {
  //   mongoc_client_pool_destroy(mongodb_client_pool);
  // }
  exit(EXIT_SUCCESS);
}
int main(int argc, char* argv[]) {
  signal(SIGINT, sigintHandler);
  init_logger();
  SetUpTracer("config/jaeger-config.yml", "url-shorten-service");
  json config_json;
  if (load_config_file("config/service-config.json", &config_json) != 0) {
    exit(EXIT_FAILURE);
  }
  int port = config_json["url-shorten-service"]["port"];

  int url_shorten_storage_port = config_json["url-shorten-storage-service"]["port"];
  std::string url_shorten_storage_addr = config_json["url-shorten-storage-service"]["addr"];
  int url_shorten_storage_conns = config_json["url-shorten-storage-service"]["connections"];
  int url_shorten_storage_timeout = config_json["url-shorten-storage-service"]["timeout_ms"];
  int url_shorten_storage_keepalive =
      config_json["url-shorten-storage-service"]["keepalive_ms"];

  ClientPool<ThriftClient<UrlShortenStorageServiceClient>> url_shorten_storage_client_pool(
      "url-shorten-storage-client", url_shorten_storage_addr, url_shorten_storage_port, 0,
      url_shorten_storage_conns, url_shorten_storage_timeout, url_shorten_storage_keepalive,
      config_json);

  // int mongodb_conns = config_json["url-shorten-mongodb"]["connections"];
  // int mongodb_timeout = config_json["url-shorten-mongodb"]["timeout_ms"];

  // int memcached_conns = config_json["url-shorten-memcached"]["connections"];
  // int memcached_timeout = config_json["url-shorten-memcached"]["timeout_ms"];

  // memcached_client_pool = init_memcached_client_pool(config_json, "url-shorten",
  //                                                    32, memcached_conns);
  // mongodb_client_pool =
  //     init_mongodb_client_pool(config_json, "url-shorten", mongodb_conns);
  // if (memcached_client_pool == nullptr || mongodb_client_pool == nullptr) {
  //   return EXIT_FAILURE;
  // }

  // mongoc_client_t* mongodb_client = mongoc_client_pool_pop(mongodb_client_pool);
  // if (!mongodb_client) {
  //   LOG(fatal) << "Failed to pop mongoc client";
  //   return EXIT_FAILURE;
  // }
  // bool r = false;
  // while (!r) {
  //   r = CreateIndex(mongodb_client, "url-shorten", "shortened_url", true);
  //   if (!r) {
  //     LOG(error) << "Failed to create mongodb index, try again";
  //     sleep(1);
  //   }
  // }
  // mongoc_client_pool_push(mongodb_client_pool, mongodb_client);

  std::mutex thread_lock;
  std::shared_ptr<TServerSocket> server_socket = get_server_socket(config_json, "0.0.0.0", port);
  TThreadedServer server(
      std::make_shared<UrlShortenServiceProcessor>(
          // std::make_shared<UrlShortenHandler>(
          //     memcached_client_pool, mongodb_client_pool, &thread_lock)),
          std::make_shared<UrlShortenHandler>(&thread_lock, &url_shorten_storage_client_pool)),
      server_socket,
      std::make_shared<TFramedTransportFactory>(),
      std::make_shared<TBinaryProtocolFactory>());

  LOG(info) << "Starting the url-shorten-service server...";
  server.serve();
}