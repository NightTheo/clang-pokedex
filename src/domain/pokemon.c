#include "pokemon.h"
#include <stdlib.h>

enum PokemonType {
    Fire
};

struct Pokemon {
    String name;
    int numberCaptured;
    PokemonType type;
};

Pokemon newPokemon(String name, int numberCaptured) {
    Pokemon p = malloc(sizeof(struct Pokemon));
    p->name = name;
    p->numberCaptured = numberCaptured;
    p->type = Fire;
    return p;
}

void freePokemon(Pokemon pokemon) {
    freeString(pokemon->name);
    free(pokemon);
}

String getPokemonName(Pokemon pokemon) {
    return pokemon->name;
}

PokemonType getPokemonType(Pokemon pokemon) {
    return pokemon->type;
}

int getNumberOfPokemonCapturedInPokemonDatasheet(Pokemon pokemon) {
    return pokemon->numberCaptured;
}