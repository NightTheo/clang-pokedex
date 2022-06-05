#include <assert.h>
#include "../test/test.h"

#include "../src/exposition/cli.h"
#include "../src/application/pokedex.service.h"


void it_should_get_salameche();
void it_should_get_pikachu();
void it_should_not_find_mewtwo();

int main() {

    it_should_get_salameche();
    it_should_get_pikachu();
    it_should_not_find_mewtwo();

    return EXIT_SUCCESS;
}

void it_should_get_salameche() {
    String actualOutput = cli("search salameche");
    String expectedOutput =  newString(
            "Salameche x3\n"
            "    Type Feu\n"
            "    Découvert la première fois le 28 mai 2022\n"
            "    Capturé la première fois le 28 mai 2022\n"
    );

    assert(assertExpectedStringEqualsActual(
            stringValue(expectedOutput),
            stringValue(actualOutput)
    ));
    freeNString(2,expectedOutput, actualOutput);
    freePokedexInstance();
}


void it_should_get_pikachu() {
    String actualOutput = cli("search pikachu");
    String expectedOutput =  newString(
            "Pikachu x0\n"
            "    Type Electrique\n"
            "    Découvert la première fois le 27 mai 2022\n"
            "    Jamais capturé\n"
    );

    assert(assertExpectedStringEqualsActual(
            stringValue(expectedOutput),
            stringValue(actualOutput)
    ));
    freeNString(2,expectedOutput, actualOutput);
    freePokedexInstance();
}

void it_should_not_find_mewtwo() {
    String actualOutput = cli("search mewtwo");
    String expectedOutput = newString("'Mewtwo' n'est pas dans le Pokedex.");

    assert(assertExpectedStringEqualsActual(
            stringValue(expectedOutput),
            stringValue(actualOutput)
    ));
    freeNString(2,expectedOutput, actualOutput);
    freePokedexInstance();
}
