#include <string.h>
#include "pokedex.service.h"

void freePokedex(Pokemon pPokemon[3]);

Pokemon searchPokemonByName(String name) {
    int pokedexSize = 3;
    Pokemon pokedex[3] = {
            newPokemon(
                    newString("Salameche"),
                    3,
                    Fire,
                    newDate(2022, MAY, 28),
                    newDate(2022, MAY, 28)
            ),
            newPokemon(newString("Pikachu"),
                       0,
                       Electric,
                       newDate(2022, MAY, 27),
                       NULL
            ),
            newPokemon(newString("Roucoule"),
                       1,
                       Flying,
                       newDate(2022, MAY, 27),
                       newDate(2022, MAY, 29)
            )
    };
    String titleSearchName = titleCase(name);
    Pokemon found = NULL;
    for(int i = 0; i < pokedexSize; i += 1) {
        if(stringAreEquals(titleSearchName, getPokemonName(pokedex[i]))) {
            found = clonePokemon(pokedex[i]);
            break;
        }
    }
    freeString(titleSearchName);
    freePokedex(pokedex);
    return found;
}

void freePokedex(Pokemon pokedex[3]) {
    for(int i = 0; i<3; i++)
        freePokemon(pokedex[i]);
}
