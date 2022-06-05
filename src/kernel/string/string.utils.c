#include "string.utils.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#include "split/split.h"

struct String {
    string value;
    int16_t length;
};

struct StringArray {
    String* array;
    int16_t size;
};

String newString(string value) {
    if(!value) return newString("");

    String string = malloc(sizeof(struct String));
    string->length = strlen(value);
    string->value = malloc(sizeof(char) * (string->length+1));
    strcpy(string->value, value);
    return string;
}

String stringCopy(String str) {
    return newString(str->value);
}

void freeString(String s) {
    free(s->value);
    s->value = NULL;
    free(s);
    s = NULL;
}

void freeNString(int numberOfStringToFree, ...) {
    va_list args;
    va_start(args, numberOfStringToFree);
    String current;
    for(int i = 0; i < numberOfStringToFree; i += 1) {
        current = (String) va_arg(args, String);
        freeString(current);
    }
    va_end(args);
}

string stringValue(String str) {
    if(!str) return NULL;
    return str->value;
}

int16_t stringLength(String str) {
    return str->length;
}

bool stringAreEquals(String str1, String str2) {
    return strcmp(str1->value, str2->value) == 0;
}

bool isStringEmpty(String str) {
    return str->length == 0;
}

String newFormattedString(string format, ...) {
    va_list args;
    va_start(args, format);
    string str = malloc(sizeof(char) * STRING_MAX_LENGTH);

    vsprintf(str, format, args); // https://stackoverflow.com/a/621882
    String formatted = newString(str);

    free(str);
    va_end(args);
    return formatted;
}

StringArray split(String str, char delimiter) {
    string* primitiveArray = NULL;
    int size = split_primitive(stringValue(str), delimiter, &primitiveArray);

    StringArray array = newEmptyStringArray();
    for(int i = 0; i < size; i += 1)
        pushStringInArray(newString(primitiveArray[i]), array);

    for (int i = 0; i < size; i++)
        free (primitiveArray[i]);
    free (primitiveArray);

    return array;
}

String getStringInArrayAtIndex(StringArray array, int index) {
    if(!array) return NULL;
    bool indexOutOfBound = index < 0 || index >= array->size;
    if(indexOutOfBound) return NULL;
    return array->array[index];
}

void freeStringArray(StringArray array) {
    for(int i = 0; i < array->size; i += 1)
        freeString(getStringInArrayAtIndex(array, i));
    free(array->array); array->array = NULL;
    free(array); array = NULL;
}

StringArray newEmptyStringArray() {
    StringArray emptyArray = malloc(sizeof(struct StringArray));
    emptyArray->array = NULL;
    emptyArray->size = 0;
    return emptyArray;
}

void pushStringInArray(String string, StringArray array) {
    int newIndex = array->size;
    array->size += 1;
    String* newArray = malloc(sizeof(String) * array->size);
    for(int i = 0; i < newIndex; i += 1)
        newArray[i] = array->array[i];
    newArray[newIndex] = string;

    if(array->array) free(array->array);
    array->array = newArray;
}

int16_t getStringArraySize(StringArray array) {
    return array->size;
}

String lowerCase(String s) {
    String copy = newString(stringValue(s));
    for(string value = stringValue(copy); *value != '\0'; value += 1)
        *value = (char)tolower(*value);
    return copy;
}

String titleCase(String str) {
    String lower = lowerCase(str);
    char* firstLetter = stringValue(lower);
    *firstLetter = (char) toupper(*firstLetter);
    return lower;
}

