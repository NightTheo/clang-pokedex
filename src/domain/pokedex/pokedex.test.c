#include "../../../test/test.h"
#include "pokedex.h"

Pokemon getPikachu();
Pokemon getPidgey();

void itShouldCreateNewPokedex();
void itShouldFreePokedex();
void itShouldPushInPokedex();

int main() {

    itShouldFreePokedex();
    itShouldCreateNewPokedex();
    itShouldPushInPokedex();

    return EXIT_SUCCESS;
}

Pokemon getPikachu() {
    return newPokemon(newString("Pikachu"),
                      0,
                      Electric,
                      newDate(2022, MAY, 27),
                      NULL);
}

Pokemon getPidgey() {
    return newPokemon(newString("Pidgey"),
                      1,
                      Flying,
                      newDate(2022, MAY, 27),
                      newDate(2022, MAY, 27));
}

void itShouldFreePokedex() {
    // Check with Valgrind
    Pokemon pokemon = newPokemon(newString("Test"),0,None,NULL,NULL);
    Pokedex pokedex = newPokedex(pokemon);
    freePokemon(pokemon);
    freePokedex(pokedex);
}


void itShouldCreateNewPokedex() {
    Pokemon pikachu = getPikachu();
    Pokedex p = newPokedex(pikachu);
    Pokemon current = getPokemonInStructPokedex(p);

    assert(assertExpectedStringEqualsActual("Pikachu", stringValue(getPokemonName(current))));

    freePokemon(pikachu); freePokemon(current);
    freePokedex(p);
}

void itShouldPushInPokedex() {
    Pokemon pikachu = getPikachu();
    Pokemon pidgey = getPidgey();
    Pokedex P = newPokedex(pikachu);

    P = pushPokemonInPokedex(pidgey, P);

    Pokemon added = getPokemonInStructPokedex(P);
    assert(assertExpectedStringEqualsActual(
            "Pidgey",
            stringValue(getPokemonName(added)))
            );

    Pokemon next = getPokemonInStructPokedex(getNextPokedex(P));
    assert(assertExpectedStringEqualsActual(
            "Pikachu",
            stringValue(getPokemonName(next)))
    );

    freePokemon(pikachu);freePokemon(pidgey);
    freePokemon(added);freePokemon(next);
    freePokedex(P);
}