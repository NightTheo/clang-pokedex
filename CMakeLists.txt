cmake_minimum_required(VERSION 3.17)
project(clang_pokedex C)

set(CMAKE_C_STANDARD 11)

enable_testing()

if(MSVC)
        set(app_compile_options "/W4 /WX")
else()
        set(app_compile_options "-Wall")
endif()

add_executable(clang_pokedex
        src/main.c
        src/exposition/cli.c src/exposition/cli.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        src/application/pokedex.service.c src/application/pokedex.service.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/exposition/adapter/cli.pokemon.adapter.c src/exposition/adapter/cli.pokemon.adapter.h
        src/kernel/date/date.c src/kernel/date/date.h src/kernel/string/split/split.c src/kernel/string/split/split.h)



############
# TESTS

# clang_pokedex_e2e
add_executable(
        clang_pokedex_e2e
        test/e2e.c
        src/exposition/cli.c src/exposition/cli.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        test/test.c test/test.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/application/pokedex.service.c src/application/pokedex.service.h
        src/exposition/adapter/cli.pokemon.adapter.c src/exposition/adapter/cli.pokemon.adapter.h
        src/kernel/date/date.h src/kernel/date/date.c
        src/kernel/string/split/split.h src/kernel/string/split/split.c
        )
add_test(NAME clang_pokedex_e2e COMMAND $<TARGET_FILE:clang_pokedex_e2e>)
#target_compile_options(clang_pokedex_e2e PUBLIC ${app_compile_options})


# string_utils_test
add_executable(
        string_utils_test
        src/kernel/string/string.utils.test.c
        test/test.c test/test.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        src/kernel/string/split/split.c)
add_test(NAME string_utils_test COMMAND $<TARGET_FILE:string_utils_test>)


# cli_pokemon_adapter_test
add_executable(
        cli_pokemon_adapter_test
        test/test.c test/test.h
        src/kernel/string/string.utils.c src/kernel/string/string.utils.h
        src/domain/pokemon.c src/domain/pokemon.h
        src/exposition/adapter/cli.pokemon.adapter.h src/exposition/adapter/cli.pokemon.adapter.c
        src/exposition/adapter/cli.pokemon.adapter.test.c
        src/kernel/date/date.c src/kernel/date/date.h
        src/kernel/string/split/split.h src/kernel/string/split/split.c)
add_test(NAME cli_pokemon_adapter_test COMMAND $<TARGET_FILE:cli_pokemon_adapter_test>)


# cli_pokemon_date_test
add_executable(
        cli_pokemon_date_test
        src/kernel/date/date.test.c
        test/test.c test/test.h
        src/kernel/date/date.h src/kernel/date/date.c
)
add_test(NAME cli_pokemon_date_test COMMAND $<TARGET_FILE:cli_pokemon_date_test>)



# split_test
add_executable(
        split_test
        src/kernel/string/split/split.test.c
        src/kernel/string/split/split.h src/kernel/string/split/split.c
        test/test.c test/test.h
)
add_test(NAME split_test COMMAND $<TARGET_FILE:split_test>)