# Минимально необходимая версия CMake
cmake_minimum_required(VERSION 3.10)

# Настройка проекта
project(FourClass
    VERSION 1.0.0
    DESCRIPTION "Class Four with arithmetic operations and constructions"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
    main.cpp
    four.cpp
)

add_executable(four ${SOURCE})

target_compile_options(four PRIVATE -Wall -Wextra -Wpedantic)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(TEST_SOURCES
    test/tests.cpp
    four.cpp
)

enable_testing()

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests PRIVATE GTest::gtest_main GTest::gtest)


target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME tests COMMAND tests)