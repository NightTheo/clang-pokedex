#ifndef CLANG_POKEDEX_CLI_POKEMON_ADAPTER_H
#define CLANG_POKEDEX_CLI_POKEMON_ADAPTER_H

#include "../../kernel/string/string.utils.h"
#include "../../domain/pokemon/pokemon.h"

String adaptToCliPokemonResponse(Pokemon pokemon);
String adaptToCliPokemonNotFoundResponse(String name);

#endif //CLANG_POKEDEX_CLI_POKEMON_ADAPTER_H
