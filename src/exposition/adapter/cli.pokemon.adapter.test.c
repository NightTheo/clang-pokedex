#include "cli.pokemon.adapter.h"
#include <assert.h>
#include <printf.h>
#include "../../kernel/string/string.utils.h"
#include "../../../test/test.h"

void itShouldAdaptPikachu();
void itShouldAdaptThreePikachu();

int main() {

    itShouldAdaptPikachu();
    itShouldAdaptThreePikachu();

    return 0;
}

void itShouldAdaptPikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"), 0);
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x0\n"
                    "Type Inconnu\n"
                    "Jamais découvert\n"
                    "Jamais capturé",
                    stringValue(response)
            )
            );
    freePokemon(pikachu);
    freeString(response);
}

void itShouldAdaptThreePikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            3
    );
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x3\n"
                    "Type Inconnu\n"
                    "Jamais découvert\n"
                    "Jamais capturé",
                    stringValue(response)
            )
    );
    freePokemon(pikachu);
    freeString(response);
}
