#ifndef CLANG_POKEDEX_POKEDEX_SERVICE_H
#define CLANG_POKEDEX_POKEDEX_SERVICE_H

#include "../kernel/string/string.utils.h"
#include "../domain/pokemon/pokemon.h"
#include "../domain/pokedex/pokedex.h"

Pokedex getPokedexInstance();
void freePokedexInstance();

Pokemon searchPokemonByName(String name);


#endif //CLANG_POKEDEX_POKEDEX_SERVICE_H
