cmake_minimum_required(VERSION 3.16)
project(MovieRecommendationSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =======================
# 📦 DEPENDÊNCIAS
# =======================

find_package(oatpp REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_library(UUID_LIB uuid)

# Plugin do gRPC (forma correta)
find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)

# =======================
# 📁 PROTOBUF + gRPC
# =======================

set(PROTO_DIR ${CMAKE_SOURCE_DIR}/grpc/protofiles)
set(PROTO_FILE ${PROTO_DIR}/database_service.proto)

set(GEN_DIR ${CMAKE_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${GEN_DIR})

set(PROTO_SRCS ${GEN_DIR}/database_service.pb.cc)
set(PROTO_HDRS ${GEN_DIR}/database_service.pb.h)
set(GRPC_SRCS ${GEN_DIR}/database_service.grpc.pb.cc)
set(GRPC_HDRS ${GEN_DIR}/database_service.grpc.pb.h)

add_custom_command(
    OUTPUT ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS
        --proto_path=${PROTO_DIR}
        --cpp_out=${GEN_DIR}
        --grpc_out=${GEN_DIR}
        --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
        ${PROTO_FILE}
    DEPENDS ${PROTO_FILE}
)

add_library(grpc_proto
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)

target_include_directories(grpc_proto PUBLIC ${GEN_DIR})

target_link_libraries(grpc_proto
    PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
)

# 🔽 ADIÇÃO AQUI (master incluído no core)
file(GLOB_RECURSE CORE_SOURCES
    lib/*.cpp
    grpc/worker/service.cpp
    grpc/master/*.cpp
)

add_library(core ${CORE_SOURCES})

target_include_directories(core PUBLIC

    include
    ${CMAKE_SOURCE_DIR}/data
    ${GEN_DIR}
    ${CMAKE_SOURCE_DIR}/data-structures
)


target_link_libraries(core
    PUBLIC
    nlohmann_json::nlohmann_json
    grpc_proto
    ${UUID_LIB}
)

# =======================
# 🌐 API (Oatpp)
# =======================

add_executable(movie_app
    src/app.cpp
)

target_include_directories(movie_app PRIVATE
    
    include
    ${GEN_DIR}
)

target_link_libraries(movie_app
    PRIVATE
    core
    oatpp::oatpp
)

add_dependencies(movie_app grpc_proto)

# =======================
# 🚀 RPC SERVER (gRPC)
# =======================

add_executable(rpc_server
    grpc/worker/server.cpp
    grpc/worker/worker_controller.cpp
)

target_include_directories(rpc_server PRIVATE
    include
    ${GEN_DIR}
)

target_link_libraries(rpc_server
    PRIVATE
    core
    grpc_proto
    gRPC::grpc++
    protobuf::libprotobuf
)

add_dependencies(rpc_server grpc_proto)

target_compile_definitions(rpc_server PRIVATE
    DB_PATH="${CMAKE_SOURCE_DIR}/data/db.json"
)
# =======================
# 🛠️ GERADOR DE BANCO
# =======================

add_executable(generate_db
    scripts/gen_rand_movies.cpp
)

target_include_directories(generate_db PRIVATE include)

target_link_libraries(generate_db
    PRIVATE
    nlohmann_json::nlohmann_json
)

# =======================
# 🧪 TESTES
# =======================



add_executable(test_runner
    tests/test.cpp
    ${TEST_SOURCES}
)

target_include_directories(test_runner PRIVATE
    include
    grpc
    ${GEN_DIR}
)

target_link_libraries(test_runner
    PRIVATE
    core
    oatpp::oatpp
    grpc_proto
)



add_dependencies(test_runner grpc_proto)