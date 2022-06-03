#include "pokemon.h"
#include <stdlib.h>

struct Pokemon {
    String name;
    int numberCaptured;
    PokemonType type;
    Date firstSeenDate;
};

Pokemon newPokemon(
        String name,
        int numberCaptured,
        PokemonType type,
        Date firstSeenDate) {
    Pokemon p = malloc(sizeof(struct Pokemon));
    p->name = name;
    p->numberCaptured = numberCaptured;
    p->type = type;
    p->firstSeenDate = firstSeenDate;
    return p;
}

void freePokemon(Pokemon pokemon) {
    freeString(pokemon->name);
    freeDate(pokemon->firstSeenDate);
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

Date getFirstSeenDateInPokemonDatasheet(Pokemon pokemon) {
    return pokemon->firstSeenDate;
}