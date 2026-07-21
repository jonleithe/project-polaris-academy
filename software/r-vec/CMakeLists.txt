cmake_minimum_required(VERSION 3.16)

project(r_vec VERSION 0.1.0 LANGUAGES CXX)

add_library(rvec src/RVec.cpp)
target_compile_features(rvec PUBLIC cxx_std_17)
target_include_directories(rvec PUBLIC include)

add_executable(r-vec src/main.cpp)
target_link_libraries(r-vec PRIVATE rvec)

target_compile_features(r-vec PRIVATE cxx_std_17)

find_path(READLINE_INCLUDE_DIR readline/readline.h)
find_library(READLINE_LIBRARY readline)
if(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    message(STATUS "Found readline: ${READLINE_LIBRARY}")
    target_include_directories(r-vec PRIVATE ${READLINE_INCLUDE_DIR})
    target_link_libraries(r-vec PRIVATE ${READLINE_LIBRARY})
    target_compile_definitions(r-vec PRIVATE HAVE_READLINE=1)
else()
    message(STATUS "Readline not found; history and line editing are disabled")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(rvec PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(r-vec PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(rvec PRIVATE /W4)
    target_compile_options(r-vec PRIVATE /W4)
endif()

include(CTest)

if(BUILD_TESTING)
    add_executable(rvec-tests tests/RVecTests.cpp)
    target_link_libraries(rvec-tests PRIVATE rvec)
    target_compile_features(rvec-tests PRIVATE cxx_std_17)
    add_test(NAME rvec_tests COMMAND rvec-tests)
endif()
