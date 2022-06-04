#include <assert.h>
#include "string.utils.h"
#include <stdlib.h>
#include "../../../test/test.h"

void testValue();
void testLength();
void testStringsAreEquals();
void itShouldCreateEmptyStringWhenValueIsNull();
void isShouldCheckIfEmptyString();
void isShouldCreateFormattedString();

int main() {
    testLength();
    testValue();
    testStringsAreEquals();
    itShouldCreateEmptyStringWhenValueIsNull();
    isShouldCheckIfEmptyString();
    isShouldCreateFormattedString();

    return EXIT_SUCCESS;
}

void testValue(){
    String str = newString("abcd");
    assert(assertExpectedStringEqualsActual(stringValue(str), "abcd"));
    freeString(str);
}

void testLength(){
    String str = newString("12345");
    assert(assertExpectedIntEqualsActual(stringLength(str), 5));
    freeString(str);
}

void testStringsAreEquals() {
    String str1 = newString("abcd");
    String str2 = newString("abcd");
    assert(stringAreEquals(str1, str2));
    freeString(str1);
    freeString(str2);
}

void itShouldCreateEmptyStringWhenValueIsNull() {
    String str = newString(NULL);
    assert(assertExpectedStringEqualsActual(
            "",
            stringValue(str)
            ));
    freeString(str);
}

void isShouldCheckIfEmptyString() {
    String s = newString("");
    assert(isStringEmpty(s));
    freeString(s);
}

void isShouldCreateFormattedString() {
    string test = "test";
    String formatted = newFormattedString("%d %s %d", 1, test, 2);
    assert(assertExpectedStringEqualsActual(
            "1 test 2",
            stringValue(formatted)
            ));
    freeString(formatted);
}