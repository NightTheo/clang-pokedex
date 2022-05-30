#include <string.h>
#include <stdbool.h>
#include "test.h"

bool assertEqualsInt(int expected, int actual) {
    return expected == actual;
}

bool assertEqualsPrimitiveString(char* expected, char* actual) {
    return strcmp(expected,actual) == 0;
}