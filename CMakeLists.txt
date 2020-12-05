cmake_minimum_required(VERSION 3.17)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(GameLogic)

add_executable(ConnectFour main.cpp)

link_libraries(ConnectFour
        BoardLogic
        Types
        Player)