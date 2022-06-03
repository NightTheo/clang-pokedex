#ifndef CLANG_POKEDEX_CLI_H
#define CLANG_POKEDEX_CLI_H

#include "../kernel/string/string.utils.h"
#include "../domain/pokemon.h"

String cli(string input);
String cliSearchPokemonByName(String name);

#endif //CLANG_POKEDEX_CLI_H
