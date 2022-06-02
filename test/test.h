#ifndef CLANG_POKEDEX_TEST_H
#define CLANG_POKEDEX_TEST_H
#include <stdbool.h>

bool assertEqualsInt(int expected, int actual);
bool assertExpectedStringEqualsActual(char* expected, char* actual);

#endif //CLANG_POKEDEX_TEST_H
