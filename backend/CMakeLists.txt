cmake_minimum_required(VERSION 3.16)
project(MovieRecommendationSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES 
    src/*.cpp
    lib/*.cpp
    lib/*tpp
)

add_executable(movie_app ${SOURCES})