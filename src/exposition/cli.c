#include "cli.h"
#include "../application/pokedex.service.h"
#include "adapter/cli.pokemon.adapter.h"
#include <stdlib.h>
#include <string.h>

String cli(string input) {
    String Input = newString(input);
    StringArray args = split(Input, ' ');
    String name = getStringInArrayAtIndex(args, 1);

    String pokemon = cliSearchPokemonByName(name);

    freeString(Input);
    freeStringArray(args);
    return pokemon;
}

String cliSearchPokemonByName(String name) {
    Pokemon found = searchPokemonByName(name);
    if(!found) return adaptToCliPokemonNotFoundResponse(name);

    String response = adaptToCliPokemonResponse(found);
    freePokemon(found);
    return response;
}
