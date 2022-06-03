#ifndef CLANG_POKEDEX_POKEMON_H
#define CLANG_POKEDEX_POKEMON_H

#include "../kernel/string/string.utils.h"
#include "../kernel/date/date.h"

// TODO renommer en PokemonDatasheet
typedef struct Pokemon* Pokemon;
typedef enum PokemonType{
    None,
    Fire,
    Electric
} PokemonType;

Pokemon newPokemon(String name, int numberCaptured, PokemonType type, Date firstSeenDate);
String getPokemonName(Pokemon pokemon);
PokemonType getPokemonType(Pokemon pokemon);
int getNumberOfPokemonCapturedInPokemonDatasheet(Pokemon pokemon);
Date getFirstSeenDateInPokemonDatasheet(Pokemon pokemon);

void freePokemon(Pokemon pokemon);

#endif //CLANG_POKEDEX_POKEMON_H
