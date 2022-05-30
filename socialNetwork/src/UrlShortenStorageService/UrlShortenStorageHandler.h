#ifndef SOCIAL_NETWORK_MICROSERVICES_SRC_URLSHORTENSTORAGESERVICE_URLSHORTENSTORAGESHANDLER_H_
#define SOCIAL_NETWORK_MICROSERVICES_SRC_URLSHORTENSTORAGESERVICE_URLSHORTENSTORAGESHANDLER_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "../../gen-cpp/UrlShortenStorageService.h"
#include "../logger.h"
#include "../tracing.h"

namespace social_network {

class UrlShortenStorageHandler : public UrlShortenStorageServiceIf {
public:
  UrlShortenStorageHandler() = default;
  ~UrlShortenStorageHandler() override = default;
  void StoreUrls(const std::vector<Url> &target_urls) override;

private:
  std::vector<std::vector<Url>> m_storage;
};

void UrlShortenStorageHandler::StoreUrls(const std::vector<Url> &target_urls) {
    m_storage.emplace_back(target_urls);
}

} // namespace social_network

#endif // SOCIAL_NETWORK_MICROSERVICES_SRC_UrlShortenSTORAGESERVICE_MEDIAHANDLER_H_
