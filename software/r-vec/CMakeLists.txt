cmake_minimum_required(VERSION 3.16)

project(r_vec VERSION 0.1.0 LANGUAGES CXX)

add_executable(r-vec src/main.cpp)

target_compile_features(r-vec PRIVATE cxx_std_17)
target_include_directories(r-vec PRIVATE include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(r-vec PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(r-vec PRIVATE /W4)
endif()

include(CTest)
