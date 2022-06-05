#include "../../../test/test.h"
#include "pokemon.h"

void itShouldCreatePokemon();
void itShouldClonePokemon();
void itShouldCheckPokemonNameEquality();

int main() {

    itShouldCreatePokemon();
    itShouldClonePokemon();
    itShouldCheckPokemonNameEquality();

    return EXIT_SUCCESS;
}

void itShouldCreatePokemon() {
    Pokemon p = newPokemon(
            newString("pokemon"),
            1,
            Fire,
            newDate(2022, JUNE, 05),
            newDate(2022, JUNE, 05)
            );

    assert(assertExpectedStringEqualsActual("pokemon",stringValue(getPokemonName(p))));
    assert(assertExpectedIntEqualsActual(1,getNumberOfPokemonCapturedInPokemonDatasheet(p)));
    assert(assertExpectedIntEqualsActual(Fire, getPokemonType(p)));

    freePokemon(p);
}

void itShouldClonePokemon() {
    Pokemon p1 = newPokemon(
            newString("pokemon1"),
            1,
            Fire,
            newDate(2022, JUNE, 05),
            newDate(2022, JUNE, 05)
    );

    Pokemon p2 = clonePokemon(p1);

    assert(assertExpectedStringEqualsActual("pokemon1",stringValue(getPokemonName(p2))));
    assert(assertExpectedIntEqualsActual(1,getNumberOfPokemonCapturedInPokemonDatasheet(p2)));
    assert(assertExpectedIntEqualsActual(Fire, getPokemonType(p2)));

    // check pointer are not the same
    assert(getPokemonName(p1) != getPokemonName(p2));
    assert(getFirstSeenDateInPokemonDatasheet(p1) != getFirstSeenDateInPokemonDatasheet(p2));
    assert(getFirstCaptureDateInPokemonDatasheet(p1) != getFirstCaptureDateInPokemonDatasheet(p2));

    freePokemon(p1); freePokemon(p2);
}

void itShouldCheckPokemonNameEquality() {
    Pokemon p = newPokemon(
            newString("Pikachu"),
            1,
            Electric,
            newDate(2022, JUNE, 05),
            newDate(2022, JUNE, 05)
    );
    String goodName = newString("Pikachu");
    String badName = newString("Pidgey");
    assert(assertIsTrue(pokemonNameEquals(p, goodName)));
    assert(assertIsFalse(pokemonNameEquals(p, badName)));

    freePokemon(p);
    freeNString(2, goodName, badName);
}

