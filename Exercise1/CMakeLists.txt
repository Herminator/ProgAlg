cmake_minimum_required(VERSION 3.9)
project(Exercise1)

set(CMAKE_CXX_STANDARD 17)
find_package(Threads)

add_executable(Exercise1
        BankAccount.h
        main.cpp
        RWLock.h)

target_link_libraries(Exercise1 ${CMAKE_THREAD_LIBS_INIT})

