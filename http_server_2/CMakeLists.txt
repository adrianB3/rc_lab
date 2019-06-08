cmake_minimum_required(VERSION 3.14)
project(http_server_2)

set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(http_server_2 main.cpp Request.cpp Request.h RequestHandler.cpp RequestHandler.h)

target_link_libraries(http_server_2 Threads::Threads)
