cmake_minimum_required(VERSION 3.10)
project(MovieRecommendationSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(oatpp REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB_RECURSE APP_SOURCES 
    src/*.cpp
    lib/*.cpp
)

add_executable(movie_app ${APP_SOURCES})

target_include_directories(movie_app PRIVATE include)

target_link_libraries(movie_app PRIVATE 
    nlohmann_json::nlohmann_json 
    oatpp::oatpp
)

add_executable(generate_db scripts/gen_rand_movies.cpp)
target_include_directories(generate_db PRIVATE include)
target_link_libraries(generate_db PRIVATE 
    nlohmann_json::nlohmann_json
)

# =======================
# TESTES (AJUSTADO)
# =======================

# Copia todas as fontes
set(TEST_SOURCES ${APP_SOURCES})

# Remove o arquivo que contém o main do app
list(FILTER TEST_SOURCES EXCLUDE REGEX "src/app.cpp")

add_executable(test_runner 
    tests/test.cpp
    ${TEST_SOURCES}
)

target_include_directories(test_runner PRIVATE include)

target_link_libraries(test_runner PRIVATE 
    nlohmann_json::nlohmann_json 
    oatpp::oatpp
)


# =======================
# gRPC + Protobuf
# =======================

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_library(UUID_LIB uuid)



set(PROTO_DIR ${CMAKE_SOURCE_DIR}/grpc/protofiles)
set(PROTO_FILE ${PROTO_DIR}/database_service.proto)

set(PROTO_SRCS ${CMAKE_BINARY_DIR}/database_service.pb.cc)
set(PROTO_HDRS ${CMAKE_BINARY_DIR}/database_service.pb.h)
set(GRPC_SRCS ${CMAKE_BINARY_DIR}/database_service.grpc.pb.cc)
set(GRPC_HDRS ${CMAKE_BINARY_DIR}/database_service.grpc.pb.h)

add_custom_command(
    OUTPUT ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS --grpc_out=${CMAKE_BINARY_DIR}
         --cpp_out=${CMAKE_BINARY_DIR}
         -I ${PROTO_DIR}
         --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`
         ${PROTO_FILE}
    DEPENDS ${PROTO_FILE}
)

add_library(grpc_proto
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)

target_include_directories(grpc_proto PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(grpc_proto
    PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
)

target_link_libraries(movie_app PRIVATE grpc_proto ${UUID_LIB})

target_link_libraries(test_runner PRIVATE grpc_proto ${UUID_LIB})