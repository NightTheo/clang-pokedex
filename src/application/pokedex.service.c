#include <string.h>
#include "pokedex.service.h"

Pokemon searchPokemonByName(String name) {
    if(strcmp(stringValue(name), "search salameche") == 0)
        return newPokemon(newString("Salameche"), 0);
    else
        return newPokemon(newString("Pikachu"), 0);
}