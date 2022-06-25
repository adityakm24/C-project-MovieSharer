cmake_minimum_required(VERSION 3.22)
project(NetflixAlt C)

set(CMAKE_C_STANDARD 99)

add_executable(NetflixAlt main.c functions.h friends.c misc.c structs.h movies.c moviefilter.c moviefilter.c)
