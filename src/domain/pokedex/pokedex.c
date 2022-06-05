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
    p->pokemon = clonePokemon(pokemon) ;
    p->next = NULL;
    return p;
}

Pokemon getPokemonByNameInPokedex(String name, Pokedex pokedex) {
    String titleName = titleCase(name);
    Pokedex iterator = pokedex;
    Pokemon found = NULL;
    while(iterator != NULL) {
        if(pokemonNameEquals(iterator->pokemon, titleName)) {
            found = clonePokemon(iterator->pokemon);
            break;
        }
        iterator = iterator->next;
    }
    freeString(titleName);
    return found;
}

void freePokedex(Pokedex head) {
    if(!head) return;
    Pokedex tmp;
    while(head != NULL) {
        tmp = head;
        freePokemon(tmp->pokemon);
        head = head->next;
        free(tmp);
    }
}

Pokemon getPokemonInStructPokedex(Pokedex pokedex) {
    return clonePokemon(pokedex->pokemon);
}

Pokedex pushPokemonInPokedex(Pokemon pokemon, Pokedex pokedex) {
    Pokedex new = newPokedex(pokemon);
    new->next = pokedex;
    return new;
}

Pokedex getNextPokedex(Pokedex pokedex) {
    if(!pokedex) return NULL;
    return pokedex->next;
}
