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