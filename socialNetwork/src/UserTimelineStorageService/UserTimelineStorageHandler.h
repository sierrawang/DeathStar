#ifndef SOCIAL_NETWORK_MICROSERVICES_SRC_USERTIMELINESTORAGESERVICE_USERTIMELINESTORAGESHANDLER_H_
#define SOCIAL_NETWORK_MICROSERVICES_SRC_USERTIMELINESTORAGESERVICE_USERTIMELINESTORAGESHANDLER_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "../../gen-cpp/UserTimelineStorageService.h"
#include "../logger.h"
#include "../tracing.h"

struct post_info {
  int64_t post_id;
  int64_t timestamp;
};

bool compare_post_info(post_info a, post_info b) {
  return a.timestamp > b.timestamp;
}

namespace social_network {

class UserTimelineStorageHandler : public UserTimelineStorageServiceIf {
public:
  UserTimelineStorageHandler() = default;
  ~UserTimelineStorageHandler() override = default;

  void UpdateUserTimeline(const int64_t user_id, const int64_t post_id,
                          const int64_t timestamp) override;
  void GetUserTimeline(std::vector<int64_t> &_return, const int64_t user_id,
                       const int32_t start, const int32_t stop) override;

private:
  std::map<int64_t, std::vector<post_info>> m_map;
};

void UserTimelineStorageHandler::UpdateUserTimeline(const int64_t user_id,
                                                    const int64_t post_id,
                                                    const int64_t timestamp) {
  LOG(debug) << "got UpdateUserTimeline call with user_id = " << user_id;
  auto it = m_map.find(user_id);
  if (it == m_map.end()) {
    m_map.emplace(user_id, std::vector<post_info>());
    it = m_map.find(user_id);
  }
  it->second.push_back(post_info{post_id, timestamp});
}

void UserTimelineStorageHandler::GetUserTimeline(std::vector<int64_t> &_return,
                                                 const int64_t user_id,
                                                 const int32_t start,
                                                 const int32_t stop) {
  LOG(debug) << "got GetUserTimeline call with user_id = " << user_id;

  // Find user timeline
  auto it = m_map.find(user_id);
  if (it == m_map.end()) {
    LOG(warning) << "User_id: doesn't exist in UserTimelineStorage";
    ServiceException se;
    se.errorCode = ErrorCode::SE_THRIFT_HANDLER_ERROR;
    se.message = "User_id: doesn't exist in UserTimelineStorage";
    throw se;
  }

  // Sort timeline in order of most recent
  auto timeline = it->second;
  std::sort(timeline.begin(), timeline.end(), compare_post_info);

  if (start >= timeline.size()) {
    LOG(warning) << "Invalid start parameter in UserTimelineStorage";
    ServiceException se;
    se.errorCode = ErrorCode::SE_THRIFT_HANDLER_ERROR;
    se.message = "Invalid start parameter in UserTimelineStorage";
    throw se;
  }

  int i = start;
  auto t_it = timeline.begin() + start;
  while (t_it != timeline.end() && i < stop) {
    _return.push_back(t_it->post_id);
    t_it++;
    i++;
  }
}

} // namespace social_network

#endif // SOCIAL_NETWORK_MICROSERVICES_SRC_USERTIMELINESTORAGESERVICE_MEDIAHANDLER_H_
