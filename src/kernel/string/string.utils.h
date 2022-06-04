#ifndef CLANG_POKEDEX_STRING_UTILS_H
#define CLANG_POKEDEX_STRING_UTILS_H

#include <stdint.h>
#include <stdbool.h>

#define STRING_MAX_LENGTH 8192 //2^13

typedef char* string;
typedef struct String* String;
typedef struct StringArray* StringArray;

String newString(string value);
void freeString(String toFree);
void freeNString(int numberOfStringToFree, ...);
char* stringValue(String string);
int16_t stringLength(String string);
bool stringAreEquals(String str1, String str2);
bool isStringEmpty(String str);
String newFormattedString(string format, ...);

StringArray newEmptyStringArray();
int16_t getStringArraySize(StringArray array);
void pushStringInArray(String string, StringArray array);
StringArray split(String str, char delimiter);
String getStringInArrayAtIndex(StringArray array, int index);
void freeStringArray(StringArray array);



#endif //CLANG_POKEDEX_STRING_UTILS_H
