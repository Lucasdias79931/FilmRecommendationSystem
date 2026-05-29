cmake_minimum_required(VERSION 3.10)
project(MovieRecommendationSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE APP_SOURCES 
    src/*.cpp
    lib/*.cpp
)

find_package(nlohmann_json REQUIRED)

add_executable(movie_app ${APP_SOURCES})

target_link_libraries(movie_app PRIVATE nlohmann_json::nlohmann_json)

add_executable(generate_db scripts/gen_rand_movies.cpp)

# (opcional, mas recomendado se usar JSON aqui também)
target_link_libraries(generate_db PRIVATE nlohmann_json::nlohmann_json)