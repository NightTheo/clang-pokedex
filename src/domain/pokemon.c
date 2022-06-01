#include "pokemon.h"
#include <stdlib.h>

enum PokemonType {
    Fire
};

struct Pokemon {
    String name;
    PokemonType type;
};

Pokemon newPokemon(String name) {
    Pokemon p = malloc(sizeof(struct Pokemon));
    p->name = name;
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