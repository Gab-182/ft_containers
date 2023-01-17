cmake_minimum_required(VERSION 3.23)
project(ft_container)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_container ./vector/vector.hpp ./tests/vector_test.cpp ./iterator/iterator.hpp ./iterator/reverse_iterator.hpp ./iterator/iterator_traits.hpp)
