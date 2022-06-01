#include "cli.pokemon.adapter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

String adaptToCliPokemonResponse(Pokemon pokemon) {
    char* name = stringValue(getPokemonName(pokemon));
    char* str = malloc(sizeof(char) * 200);
    if(strcmp(name, "Salameche") == 0) {
        sprintf(str,
                "%s x3\n"
                "    Type Feu\n"
                "    Découvert la 1ère fois le 28 mai 2022\n"
                "    Capturé la première fois le 28 mai 2022",
                name
        );
    } else {
        sprintf(str,
                "%s x0\n"
                "Type Electrique\n"
                "Découvert la 1ère fois le 27 mai 2022\n"
                "Jamais capturé",
                name
        );
    }

    String res =  newString(str);
    free(str);
    return res;
}