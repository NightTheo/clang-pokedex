cmake_minimum_required(VERSION 3.17)
project(clang_pokedex C)

set(CMAKE_C_STANDARD 11)
include(CTest)

add_executable(clang_pokedex
        src/main.c
        src/exposition/cli.c src/exposition/cli.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        src/application/pokedex.service.c src/application/pokedex.service.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/exposition/adapter/cli.pokemon.adapter.c src/exposition/adapter/cli.pokemon.adapter.h
        src/kernel/date/date.c src/kernel/date/date.h)


# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html#handling-a-large-number-of-tests
enable_testing()

add_executable(clang_pokedex_e2e
        test/e2e.c
        src/exposition/cli.c src/exposition/cli.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        test/test.c test/test.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/application/pokedex.service.c src/application/pokedex.service.h
        src/exposition/adapter/cli.pokemon.adapter.c src/exposition/adapter/cli.pokemon.adapter.h
        src/kernel/date/date.h src/kernel/date/date.c
        )

add_executable(
        string_utils_test
        src/kernel/string/string.utils.test.c
        test/test.c test/test.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        )
add_test(NAME string_utils_test COMMAND $<TARGET_FILE:string_utils_test>)

add_executable(
        cli_pokemon_adapter_test
        test/test.c test/test.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/exposition/adapter/cli.pokemon.adapter.h src/exposition/adapter/cli.pokemon.adapter.c
        src/exposition/adapter/cli.pokemon.adapter.test.c
        src/kernel/date/date.c src/kernel/date/date.h)
add_test(NAME cli_pokemon_adapter_test COMMAND $<TARGET_FILE:cli_pokemon_adapter_test>)

add_executable(
        cli_pokemon_date_test
        src/kernel/date/date.test.c
        test/test.c test/test.h
        src/kernel/date/date.h src/kernel/date/date.c
)
add_test(NAME cli_pokemon_date_test COMMAND $<TARGET_FILE:cli_pokemon_date_test>)