#include "string.utils.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char* value;
    int16_t length;
};

String newString(char* value) {
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

char* stringValue(String str) {
    return str->value;
}

int16_t stringLength(String str) {
    return str->length;
}

bool stringAreEquals(String str1, String str2) {
    return strcmp(str1->value, str2->value) == 0;
}