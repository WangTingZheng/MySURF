cmake_minimum_required(VERSION 3.16)
project(MySURF)

set(CMAKE_CXX_STANDARD 11)

add_executable(MySURF
        main.cpp
        src/bitmap.cc
        src/bitmap.h
        src/bitmap_test.cc
        src/bitmap_test.h
        src/binarytree.cc
        src/binarytree.h
        src/values.cc
        src/values.h
        src/values_test.cc
        src/values_test.h
        src/binarytree_test.cc
        src/binarytree_test.h
        )
