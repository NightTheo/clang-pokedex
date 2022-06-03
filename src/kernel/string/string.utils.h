#ifndef CLANG_POKEDEX_STRING_UTILS_H
#define CLANG_POKEDEX_STRING_UTILS_H

#include <stdint.h>
#include <stdbool.h>

#define StringUtils struct _StringUtils _ = {newString, freeString};_

typedef char* string;
typedef struct String* String;
struct _StringUtils {
    String (*newString)(string value);
    void (*freeString)(String str);
};

String newString(string value);
void freeString(String toFree);
char* stringValue(String string);
int16_t stringLength(String string);
bool stringAreEquals(String str1, String str2);



#endif //CLANG_POKEDEX_STRING_UTILS_H
