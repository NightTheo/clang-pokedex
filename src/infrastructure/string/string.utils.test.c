#include <assert.h>
#include "string.utils.h"
#include "../../../test/test.h"

void testValue();
void testLength();
void testStringsAreEquals();

int main(int argc, char** argv) {

    testLength();
    testValue();
    testStringsAreEquals();

    return 0;
}

void testValue(){
    String str = newString("abcd");
    assert(assertEqualsPrimitiveString(stringValue(str), "abcd"));
    freeString(str);
}

void testLength(){
    String str = newString("12345");
    assert( assertEqualsInt(stringLength(str), 5 ));
    freeString(str);
}

void testStringsAreEquals() {
    String str1 = newString("abcd");
    String str2 = newString("abcd");
    assert(stringAreEquals(str1, str2));
    freeString(str1);
    freeString(str2);
}