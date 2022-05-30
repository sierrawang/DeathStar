add_executable(
    PostStorageStorageService
    PostStorageStorageService.cpp
    ${THRIFT_GEN_CPP_DIR}/PostStorageStorageService.cpp
    ${THRIFT_GEN_CPP_DIR}/social_network_types.cpp
)


target_link_libraries(
    PostStorageStorageService
    nlohmann_json::nlohmann_json
    ${THRIFT_LIB}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
    jaegertracing
)

install(TARGETS PostStorageStorageService DESTINATION ./)
