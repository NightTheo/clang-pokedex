#include "pokedex.h"
#include "../pokemon/pokemon.h"
#include <stdlib.h>
#include <stdbool.h>
#include <printf.h>

struct Pokedex {
    Pokemon pokemon;
    Pokedex next;
};

Pokedex newPokedex(Pokemon pokemon) {
    Pokedex p = malloc(sizeof(struct Pokedex));
    p->pokemon = NULL;//pokemon;// clonePokemon(pokemon) ;
    p->next = NULL;
    return p;
}

Pokemon getPokemonByNameInPokedex(String name, Pokedex pokedex) {
    String titleName = titleCase(name);
    Pokedex iterator = pokedex;
    Pokemon found = NULL;
    while(iterator != NULL) {
        if(pokemonNameEquals(pokedex->pokemon, titleName)) {
            found = clonePokemon(pokedex->pokemon);
            break;
        }
        iterator = iterator->next;
    }
    freeString(titleName);
    return found;
}

void freePokedex(Pokedex head) {
    if(!head) return;
    free(head);
    head = NULL;
    /*
    Pokedex tmp;
    while(head != NULL) {
        printf("POKEMON: "); printf("%s\n", stringValue(getPokemonName(head->pokemon)));
        tmp = head;
        freePokemon(tmp->pokemon);
        head = head->next;
        free(tmp);
    }*/
}

Pokemon getCurrentPokemonInPokedex(Pokedex pokedex) {
    return clonePokemon(pokedex->pokemon);
}
