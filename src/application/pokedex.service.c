#include <string.h>
#include "pokedex.service.h"
#include "../domain/pokedex/pokedex.h"
#include "../domain/pokedex.repository.h"

// Pokedex SINGLETON---------
Pokedex POKEDEX = NULL;
//---------------------------

Pokedex getPokedexInstance() {
    if(!POKEDEX) POKEDEX = getPokedex();
    return POKEDEX;
}

void freePokedexInstance() {
    freePokedex(POKEDEX);
    POKEDEX = NULL;
}

Pokemon searchPokemonByName(String name) {
    Pokedex pokedex = getPokedexInstance();
    return getPokemonByNameInPokedex(name, pokedex);
}
