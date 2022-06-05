#ifndef CLANG_POKEDEX_POKEDEX_H
#define CLANG_POKEDEX_POKEDEX_H

#include "../pokemon/pokemon.h"

typedef struct Pokedex* Pokedex;

Pokedex newPokedex(Pokemon pokemon);
void freePokedex(Pokedex pokedex);
Pokemon getPokemonInStructPokedex(Pokedex pokedex);
Pokemon getPokemonByNameInPokedex(String name, Pokedex pokedex);
Pokedex pushPokemonInPokedex(Pokemon pokemon, Pokedex pokedex);
Pokedex getNextPokedex(Pokedex pokedex);


#endif //CLANG_POKEDEX_POKEDEX_H
