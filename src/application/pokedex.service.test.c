#include <assert.h>
#include "../../test/test.h"

#include "pokedex.service.h"



void itShouldGetPokemonByName();

int main() {

    itShouldGetPokemonByName();


    return EXIT_SUCCESS;
}


void itShouldGetPokemonByName() {
    String name = newString("pikachu");
    Pokemon found = searchPokemonByName(name);

    assert(assertExpectedStringEqualsActual("Pikachu", stringValue(getPokemonName(found))));
    assert(assertExpectedIntEqualsActual(0,getNumberOfPokemonCapturedInPokemonDatasheet(found)));


    freePokemon(found);
    freeString(name);
}