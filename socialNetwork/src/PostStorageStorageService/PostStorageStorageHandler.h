#ifndef SOCIAL_NETWORK_MICROSERVICES_SRC_POSTSTORAGESTORAGESERVICE_POSTSTORAGESTORAGESHANDLER_H_
#define SOCIAL_NETWORK_MICROSERVICES_SRC_POSTSTORAGESTORAGESERVICE_POSTSTORAGESTORAGESHANDLER_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "../../gen-cpp/PostStorageStorageService.h"
#include "../logger.h"
#include "../tracing.h"

namespace social_network {

class PostStorageStorageHandler : public PostStorageStorageServiceIf {
public:
  PostStorageStorageHandler() = default;
  ~PostStorageStorageHandler() override = default;

  void StorePost(const int64_t req_id, const Post &post,
                 const std::map<std::string, std::string> &carrier) override;
  void ReadPost(Post &_return, const int64_t req_id, const int64_t post_id,
                const std::map<std::string, std::string> &carrier) override;
  void ReadPosts(std::vector<Post> &_return, const int64_t req_id,
                 const std::vector<int64_t> &post_ids,
                 const std::map<std::string, std::string> &carrier) override;

private:
  std::map<int64_t, Post> m_posts_db;
};

void PostStorageStorageHandler::StorePost(
    const int64_t req_id, const Post &post,
    const std::map<std::string, std::string> &carrier) {
  LOG(info) << "Storing post in PostStorageStorageHandler";
  m_posts_db.emplace(post.post_id, post);
}

void PostStorageStorageHandler::ReadPost(
    Post &_return, const int64_t req_id, const int64_t post_id,
    const std::map<std::string, std::string> &carrier) {
  LOG(debug) << "got ReadPost call with post_id = " << post_id;
  try {
    _return = m_posts_db.at(post_id);
  } catch (const std::out_of_range &e) {
    // This is assuming that all valid post ids are positive
    _return.post_id = -1;
  }
  LOG(debug) << "ReadPost return post_id = " << _return.post_id;
}

void PostStorageStorageHandler::ReadPosts(
    std::vector<Post> &_return, const int64_t req_id,
    const std::vector<int64_t> &post_ids,
    const std::map<std::string, std::string> &carrier) {
  LOG(debug) << "got ReadPosts call";
  for (auto post_id : post_ids) {
    try {
      _return.push_back(m_posts_db.at(post_id));
    } catch (const std::out_of_range &e) {
      LOG(debug) << "post_id " << post_id << " does not exist in PostStorageStorage";
    }
  }
}

} // namespace social_network

#endif // SOCIAL_NETWORK_MICROSERVICES_SRC_PostStorageSTORAGESERVICE_MEDIAHANDLER_H_
