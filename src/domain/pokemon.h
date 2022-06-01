#ifndef CLANG_POKEDEX_POKEMON_H
#define CLANG_POKEDEX_POKEMON_H

#include "../infrastructure/string/string.utils.h"

typedef struct Pokemon* Pokemon;
typedef enum PokemonType PokemonType;

Pokemon newPokemon(String name);
String getPokemonName(Pokemon pokemon);
PokemonType getPokemonType(Pokemon pokemon);
void freePokemon(Pokemon pokemon);

#endif //CLANG_POKEDEX_POKEMON_H
