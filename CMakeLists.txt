cmake_minimum_required(VERSION 3.17)
project(clang_pokedex C)

set(CMAKE_C_STANDARD 11)
include(CTest)

add_executable(clang_pokedex
        src/main.c
        src/exposition/cli.c src/exposition/cli.h
        src/infrastructure/string/string.utils.c src/infrastructure/string/string.utils.h
        src/application/pokedex.service.c src/application/pokedex.service.h src/domain/pokemon.c src/domain/pokemon.h)


# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html#handling-a-large-number-of-tests
enable_testing()

add_executable(clang_pokedex_e2e
        test/e2e.c
        src/exposition/cli.c src/exposition/cli.h
        src/infrastructure/string/string.utils.c src/infrastructure/string/string.utils.h
        test/test.c test/test.h)

add_executable(clang_pokedex_test
        src/main.c
        src/exposition/cli.h
        src/infrastructure/string/string.utils.c src/infrastructure/string/string.utils.h
        src/infrastructure/string/string.utils.test.c
        test/test.c test/test.h)

add_executable(
        string_utils_test
        src/infrastructure/string/string.utils.test.c
        test/test.c test/test.h
        src/infrastructure/string/string.utils.c src/infrastructure/string/string.utils.h
        )
add_test(NAME string_utils_test COMMAND $<TARGET_FILE:string_utils_test>)