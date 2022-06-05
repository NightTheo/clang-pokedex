#ifndef CLANG_POKEDEX_TEST_H
#define CLANG_POKEDEX_TEST_H
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool assertExpectedIntEqualsActual(int expected, int actual);
bool assertExpectedStringEqualsActual(char* expected, char* actual);
bool assertIsNull(void* var);
bool assertIsNotNull(void* var);
bool assertIsTrue(bool var);
bool assertIsFalse(bool var);

#endif //CLANG_POKEDEX_TEST_H
