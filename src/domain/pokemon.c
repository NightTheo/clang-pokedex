#include "pokemon.h"
#include <stdlib.h>

struct Pokemon {
    String name;
    int numberCaptured;
    PokemonType type;
    Date firstSeenDate;
    Date firstCaptureDate;
};

Pokemon newPokemon(
        String name,
        int numberCaptured,
        PokemonType type,
        Date firstSeenDate,
        Date firstCaptureDate
        ) {
    Pokemon p = malloc(sizeof(struct Pokemon));
    p->name = name;
    p->numberCaptured = numberCaptured;
    p->type = type;
    p->firstSeenDate = firstSeenDate;
    p->firstCaptureDate = firstCaptureDate;
    return p;
}

void freePokemon(Pokemon pokemon) {
    freeString(pokemon->name);
    freeDate(pokemon->firstSeenDate);
    freeDate(pokemon->firstCaptureDate);
    free(pokemon);
    pokemon = NULL;
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

Date getFirstCaptureDateInPokemonDatasheet(Pokemon pokemon) {
    return pokemon->firstCaptureDate;
}

Pokemon clonePokemon(Pokemon pokemon) {
    return newPokemon(
            stringCopy(pokemon->name),
            pokemon->numberCaptured,
            pokemon->type,
            dateCopy(pokemon->firstSeenDate),
            dateCopy(pokemon->firstCaptureDate)
            );
}
