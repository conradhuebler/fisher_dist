cmake_minimum_required(VERSION 2.6)
project(fisher)

add_executable(fisher main.cpp)
set_property(TARGET fisher PROPERTY CXX_STANDARD 14)
install(TARGETS fisher RUNTIME DESTINATION bin)
