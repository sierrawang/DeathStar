#ifndef SOCIAL_NETWORK_MICROSERVICES_SRC_MEDIASERVICE_MEDIAHANDLER_H_
#define SOCIAL_NETWORK_MICROSERVICES_SRC_MEDIASERVICE_MEDIAHANDLER_H_

#include <chrono>
#include <iostream>
#include <string>

#include "../../gen-cpp/UserStorageService.h"
#include "../logger.h"
#include "../tracing.h"

// 2018-01-01 00:00:00 UTC
#define CUSTOM_EPOCH 1514764800000

namespace social_network {

class UserStorageHandler : public UserStorageServiceIf {
public:
    UserStorageHandler() = default;
    ~UserStorageHandler() override = default;

    virtual void WriteUser(const User& user) override;
    virtual void ReadUser(User& _return, const int64_t user_id) override;
    virtual void FindUser(User& _return, const std::string& username) override;

private:
    std::map<int64_t, User> m_map;
};

void UserStorageHandler::WriteUser(const User& user) {
    LOG(debug) << "got WriteUser call with user_id = " << user.user_id;
    assert(user.user_id != -1);
    m_map[user.user_id] = user;
}

void UserStorageHandler::ReadUser(User& _return, const int64_t user_id) {
    LOG(debug) << "got ReadUser call with user_id = " << user_id;
    try {
        _return = m_map.at(user_id);
    } catch (const std::out_of_range& e) {
        _return.user_id = -1;
    }
    LOG(debug) << "ReadUser return user_id = " << _return.user_id;
}

void UserStorageHandler::FindUser(User& _return, const std::string& username) {
    LOG(debug) << "got FindUser call with user_id = " << username;
    for (auto pair : m_map) {
        if (pair.second.username == username) {
            _return = pair.second;
            return;
        }
    }
    _return.user_id = -1;
}

}  // namespace social_network

#endif  // SOCIAL_NETWORK_MICROSERVICES_SRC_MEDIASERVICE_MEDIAHANDLER_H_
