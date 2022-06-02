#include <string.h>
#include <stdbool.h>
#include "test.h"
#include <stdio.h>

bool assertEqualsInt(int expected, int actual) {
    if(expected != actual) {
        printf("\nFAIL: expected: %d, actual: %d", expected, actual);
    }
    return expected == actual;
}

bool assertExpectedStringEqualsActual(char* expected, char* actual) {
    if(strcmp(expected,actual) != 0) {
        printf("\nFAIL");
        printf("\nexpected: \n%s\n", expected);
        printf("\nactual: \n%s\n", actual);
    }
    return strcmp(expected,actual) == 0;
}