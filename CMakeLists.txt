cmake_minimum_required(VERSION 3.0)

project(cs238p LANGUAGES C)

add_executable(cs238p main.c)

install(TARGETS cs238p RUNTIME DESTINATION bin)
