#include "../domain/pokedex.repository.h"
#include <stdlib.h>
#include <stdio.h>

Pokedex getPokedex() {
    Pokemon pokemons[3] = {
            newPokemon(newString("Salameche"),3,Fire,newDate(2022, MAY, 28),newDate(2022, MAY, 28)),
            newPokemon(newString("Pikachu"),0,Electric,newDate(2022, MAY, 27),NULL),
            newPokemon(newString("Roucoule"),1,Flying,newDate(2022, MAY, 27),newDate(2022, MAY, 29))
    };
    Pokedex pokedex = newPokedex(pokemons[0]);
    for(int i = 1; i < 3; i ++) pokedex = pushPokemonInPokedex(pokemons[i], pokedex);
    for(int i = 0; i < 3; i ++) freePokemon(pokemons[i]);
    return pokedex;
}


void savePokedex() {
    printf("Save Pokedex");
}
