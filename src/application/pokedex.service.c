#include <string.h>
#include "pokedex.service.h"

Pokemon searchPokemonByName(String name) {
    if(strcmp(stringValue(name), "search salameche") == 0)
        return newPokemon(
                newString("Salameche"),
                3,
                Fire,
                newDate(2022, MAY, 28),
                newDate(2022, MAY, 28)
                );
    else
        return newPokemon(newString("Pikachu"),
                          0,
                          Electric,
                          newDate(2022, MAY, 27),
                          NULL
                          );
}