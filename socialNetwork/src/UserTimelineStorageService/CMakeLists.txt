add_executable(
    UserTimelineStorageService
    UserTimelineStorageService.cpp
    ${THRIFT_GEN_CPP_DIR}/UserTimelineStorageService.cpp
    ${THRIFT_GEN_CPP_DIR}/social_network_types.cpp
)


target_link_libraries(
    UserTimelineStorageService
    nlohmann_json::nlohmann_json
    ${THRIFT_LIB}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
    jaegertracing
)

install(TARGETS UserTimelineStorageService DESTINATION ./)
