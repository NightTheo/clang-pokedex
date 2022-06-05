#include <assert.h>
#include "../../test/test.h"

#include "pokedex.service.h"



void itShouldGetPokemonByName();
void itShouldNotFoundPokemon();
void itShouldFreePokedex();

int main() {

    //itShouldGetPokemonByName();
    //itShouldNotFoundPokemon();

    return EXIT_SUCCESS;
}

void itShouldGetPokemonByName() {
    String name = newString("pikachu");
    Pokemon found = searchPokemonByName(name);

    assert(assertExpectedStringEqualsActual("Pikachu", stringValue(getPokemonName(found))));
    assert(assertExpectedIntEqualsActual(0,getNumberOfPokemonCapturedInPokemonDatasheet(found)));

    freePokemon(found);
    freeString(name);
    freePokedexInstance();
}

void itShouldNotFoundPokemon() {
    String name = newString("mewtwo");
    Pokemon found = searchPokemonByName(name);

    assert(assertIsNull(found));

    freeString(name);
}