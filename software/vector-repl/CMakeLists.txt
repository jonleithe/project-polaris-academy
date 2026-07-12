cmake_minimum_required(VERSION 3.16)

project(vector_repl VERSION 1.0.0 LANGUAGES CXX)

add_library(rvector src/RVector.cpp)
target_include_directories(rvector PUBLIC include)
target_compile_features(rvector PUBLIC cxx_std_17)

add_executable(vector-repl src/main.cpp)
target_link_libraries(vector-repl PRIVATE rvector)

find_path(READLINE_INCLUDE_DIR readline/readline.h)
find_library(READLINE_LIBRARY readline)
if(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    message(STATUS "Found readline: ${READLINE_LIBRARY}")
    target_include_directories(vector-repl PRIVATE ${READLINE_INCLUDE_DIR})
    target_link_libraries(vector-repl PRIVATE ${READLINE_LIBRARY})
    target_compile_definitions(vector-repl PRIVATE HAVE_READLINE=1)
else()
    message(STATUS "Readline not found; REPL history and line editing are disabled")
endif()

foreach(target rvector vector-repl)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    elseif(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    endif()
endforeach()

include(CTest)

if(BUILD_TESTING)
    add_executable(rvector-tests tests/RVectorTests.cpp)
    target_link_libraries(rvector-tests PRIVATE rvector)
    add_test(NAME rvector_tests COMMAND rvector-tests)
endif()
