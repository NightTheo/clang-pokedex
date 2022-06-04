#include "string.utils.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

struct String {
    string value;
    int16_t length;
};

String newString(string value) {
    if(!value) return newString("");

    String string = malloc(sizeof(struct String));
    string->length = strlen(value);
    string->value = malloc(sizeof(char) * (string->length+1));
    strcpy(string->value, value);
    return string;
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