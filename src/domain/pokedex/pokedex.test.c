#include "../../../test/test.h"
#include "pokedex.h"

void itShouldCreateNewPokedex();
void itShouldFreePokedex();

int main() {

    itShouldFreePokedex();
    //itShouldCreateNewPokedex();

    return EXIT_SUCCESS;
}


void itShouldFreePokedex() {
    // Check with Valgrind
    Pokemon pokemon = newPokemon(newString("Test"),0,None,NULL,NULL);
    freePokemon(pokemon);
}


void itShouldCreateNewPokedex() {
    Pokemon pikachu = newPokemon(newString("Pikachu"),
                                 0,
                                 Electric,
                                 newDate(2022, MAY, 27),
                                 NULL
    );
    Pokedex p = newPokedex(pikachu);
    Pokemon current = getCurrentPokemonInPokedex(p);

    assert(assertExpectedStringEqualsActual("Pikachu", stringValue(getPokemonName(current))));

    freePokemon(pikachu); freePokemon(current);
    freePokedex(p);
}