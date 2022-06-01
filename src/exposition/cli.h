#ifndef CLANG_POKEDEX_CLI_H
#define CLANG_POKEDEX_CLI_H

#include "../infrastructure/string/string.utils.h"
#include "../domain/pokemon.h"

String cli(char* input);
String cliSearchPokemonByName(String name);

#endif //CLANG_POKEDEX_CLI_H
