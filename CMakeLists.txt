cmake_minimum_required(VERSION 3.23)

project(ft_containers_D)

SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers
        ./vector/vector.hpp
        ./tests/vector_tests/vector_test.cpp
        ./tests/vector_tests/Original.cpp
        ./iterator/iterator.hpp
        ./iterator/reverse_iterator.hpp
        ./iterator/iterator_traits.hpp
        ./utils/enable_if.hpp
        ./utils/is_integral.hpp
        ./utils/Algorithms.hpp map/map.hpp utils/pair.hpp)
