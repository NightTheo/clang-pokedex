#include "cli.h"
#include "../application/pokedex.service.h"
#include "adapter/cli.pokemon.adapter.h"

String cli(string input) {
    String name = newString(input);
    String pokemon = cliSearchPokemonByName(name);
    freeString(name);
    return pokemon;
}

String cliSearchPokemonByName(String name) {
    Pokemon search = searchPokemonByName(name);
    String response = adaptToCliPokemonResponse(search);
    freePokemon(search);
    return response;
}