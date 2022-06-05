#include "../domain/pokedex.repository.h"
#include <stdlib.h>
#include <stdio.h>

/*
Pokemon pokedex_[3] = {
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
 */

Pokedex getPokedex() {
    Pokemon pikachu = newPokemon(newString("Pikachu"),
                                 0,
                                 Electric,
                                 newDate(2022, MAY, 27),
                                 NULL
    );
    Pokedex pokedex = newPokedex(pikachu);
    freePokemon(pikachu);
    return pokedex;
}


void savePokedex() {
    printf("Save Pokedex");
}
