#include "../src/exposition/cli.h"
#include <assert.h>
#include "../test/test.h"


void it_should_get_salameche();
void it_should_get_pikachu();

int main() {

    it_should_get_salameche();
    it_should_get_pikachu();

    return 0;
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
    freeString(actualOutput);
    freeString(expectedOutput);
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
    freeString(actualOutput);
    freeString(expectedOutput);
}
