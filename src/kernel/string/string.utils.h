#ifndef CLANG_POKEDEX_STRING_UTILS_H
#define CLANG_POKEDEX_STRING_UTILS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct String* String;
typedef struct StringUtils {
    String (*newString)(char* value);
} StringUtils;

String newString(char* value);
void freeString(String toFree);
char* stringValue(String string);
int16_t stringLength(String string);
bool stringAreEquals(String str1, String str2);

#endif //CLANG_POKEDEX_STRING_UTILS_H
