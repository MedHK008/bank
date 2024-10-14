cmake_minimum_required(VERSION 3.28)
project(bank)

set(CMAKE_CXX_STANDARD 20)

add_executable(bank main.cpp
        Bank.cpp
        Bank.h
        Account.cpp
        Account.h)
