#include <string.h>
#include <stdbool.h>
#include "test.h"
#include <stdio.h>

bool assertExpectedIntEqualsActual(int expected, int actual) {
    if(expected != actual) {
        printf("\nFAIL: expected: %d, actual: %d\n", expected, actual);
    }
    return expected == actual;
}

bool assertExpectedStringEqualsActual(char* expected, char* actual) {
    if(!expected || !actual) return false;
    if(strcmp(expected,actual) != 0) {
        printf("\nFAIL");
        printf("\nexpected: \n%s\n", expected);
        printf("\nactual: \n%s\n", actual);
    }
    return strcmp(expected,actual) == 0;
}

bool assertIsNull(void* var) {
    if(NULL != var) {
        printf("\nFAIL: pointer is NOT null\n");
    }
    return NULL == var;
}

bool assertIsNotNull(void* var) {
    if(NULL == var) {
        printf("\nFAIL: pointer IS null\n");
    }
    return NULL != var;
}
