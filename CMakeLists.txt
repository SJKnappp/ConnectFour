cmake_minimum_required(VERSION 3.17)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(GameLogic)
add_subdirectory(spiller)
add_subdirectory(BoardTypes)

add_executable(ConnectFour main.cpp)

target_link_libraries(ConnectFour
        Player
        BoardLogic)
