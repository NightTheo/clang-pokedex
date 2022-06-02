#ifndef CLANG_POKEDEX_POKEMON_H
#define CLANG_POKEDEX_POKEMON_H

#include "../kernel/string/string.utils.h"

// TODO renommer en PokemonDatasheet
typedef struct Pokemon* Pokemon;
typedef enum PokemonType PokemonType;

Pokemon newPokemon(String name, int numberCaptured);
String getPokemonName(Pokemon pokemon);
PokemonType getPokemonType(Pokemon pokemon);
int getNumberOfPokemonCapturedInPokemonDatasheet(Pokemon pokemon);

void freePokemon(Pokemon pokemon);

#endif //CLANG_POKEDEX_POKEMON_H
