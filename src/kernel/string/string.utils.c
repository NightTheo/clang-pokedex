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

void freeString(String string) {
    free(string->value);
    string->value = NULL;
    free(string);
    string = NULL;
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

String newFormattedString(String format, ...) {
    va_list args;
    va_start(args, format);
    string str = malloc(sizeof(char) * STRING_MAX_LENGTH);

    vsprintf(str, stringValue(format), args);
    String formatted = newString(str);

    free(str);
    va_end(args);
    return formatted;
}