#ifndef CLANG_POKEDEX_TEST_H
#define CLANG_POKEDEX_TEST_H
#include <stdbool.h>

bool assertExpectedIntEqualsActual(int expected, int actual);
bool assertExpectedStringEqualsActual(char* expected, char* actual);
bool assertIsNull(void* var);
bool assertIsNotNull(void* var);

#endif //CLANG_POKEDEX_TEST_H
