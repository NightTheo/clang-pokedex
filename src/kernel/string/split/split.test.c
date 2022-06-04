#include "split.h"
#include "../../../../test/test.h"
#include <stdlib.h>

void itShouldSplitPrimitiveString();

int main() {

    itShouldSplitPrimitiveString();

    return EXIT_SUCCESS;
}


void itShouldSplitPrimitiveString() {
    char *str = "I Want to Break Free.";

    char **arr;
    int size = split_primitive(str, ' ', &arr);

    assertExpectedStringEqualsActual("I", arr[0]);
    assertExpectedStringEqualsActual("Want", arr[1]);
    assertExpectedStringEqualsActual("to", arr[2]);
    assertExpectedStringEqualsActual("Break", arr[3]);
    assertExpectedStringEqualsActual("Free.", arr[4]);

    for (int i = 0; i < size; i++) free (arr[i]);
    free (arr);
}