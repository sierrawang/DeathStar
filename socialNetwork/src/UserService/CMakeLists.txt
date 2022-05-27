add_executable(
    UserService
    UserService.cpp
    ${THRIFT_GEN_CPP_DIR}/UserService.cpp
    ${THRIFT_GEN_CPP_DIR}/social_network_types.cpp
    ${THRIFT_GEN_CPP_DIR}/SocialGraphService.cpp
    ${THRIFT_GEN_CPP_DIR}/UserStorageService.cpp
)


target_include_directories(
    UserService PRIVATE
    /usr/local/include/jwt
    /usr/local/include/jaegertracing
)

target_link_libraries(
    UserService
    nlohmann_json::nlohmann_json
    ${THRIFT_LIB}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
    jaegertracing
    OpenSSL::SSL
)

install(TARGETS UserService DESTINATION ./)
