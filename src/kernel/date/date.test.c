#include <assert.h>
#include "date.h"
#include "../../../test/test.h"


void itShouldCreateDate();
void itShouldNotCreateDateWithMonthInferiorThanJanuary();
void itShouldNotCreateDateWithMonthSuperiorThanDecember();
void itShouldNotCreateDateWithDayInferiorThanOne();
void itShouldNotCreateDateWithDaySuperiorThanMaxDayInJanuary();
void itShouldNotCreateTheTwentyNinthFebruaryOfACommonYear();
void itShouldNotCreateDateWithDaySuperiorThanMaxDayInApril();
void itShouldCreateTheTwentyNinthFebruaryOfALeapYear();
void itShouldCreateTheTwentyNinthFebruaryOfListOfLeapYears();

int main() {

    itShouldCreateDate();
    itShouldNotCreateDateWithMonthInferiorThanJanuary();
    itShouldNotCreateDateWithMonthSuperiorThanDecember();
    itShouldNotCreateDateWithDayInferiorThanOne();
    itShouldNotCreateDateWithDaySuperiorThanMaxDayInJanuary();
    itShouldNotCreateDateWithDaySuperiorThanMaxDayInApril();
    itShouldNotCreateTheTwentyNinthFebruaryOfACommonYear();
    itShouldCreateTheTwentyNinthFebruaryOfALeapYear();
    itShouldCreateTheTwentyNinthFebruaryOfListOfLeapYears();

    return 0;
}

void itShouldCreateDate() {
    Date d = newDate(2022, JUNE, 3);
    assert(assertExpectedIntEqualsActual(2022, getYearOf(d)));
    assert(assertExpectedIntEqualsActual(JUNE, getMonthOf(d)));
    assert(assertExpectedIntEqualsActual(3, getDayOf(d)));

    freeDate(d);
}

void itShouldNotCreateDateWithMonthInferiorThanJanuary() {
    Date monthStrictInfToJanuary = newDate(2022, JANUARY - 1, 3);
    assert(assertIsNull(monthStrictInfToJanuary));
    freeDate(monthStrictInfToJanuary);
}

void itShouldNotCreateDateWithMonthSuperiorThanDecember() {
    Date monthStrictSupToDecember = newDate(2022, DECEMBER + 1, 3);
    assert(assertIsNull(monthStrictSupToDecember));
    freeDate(monthStrictSupToDecember);
}

void itShouldNotCreateDateWithDayInferiorThanOne() {
    Date dayToZero = newDate(2022, JUNE, 0);
    assert(assertIsNull(dayToZero));
    freeDate(dayToZero);
}

void itShouldNotCreateDateWithDaySuperiorThanMaxDayInJanuary() {
    Date lastDayOfJanuary = newDate(2022, JANUARY, 31);
    assert(assertIsNotNull(lastDayOfJanuary));

    Date outOfJanuary = newDate(2022, JANUARY, 32);
    assert(assertIsNull(outOfJanuary));

    freeDate(lastDayOfJanuary);
    freeDate(outOfJanuary);
}

void itShouldNotCreateDateWithDaySuperiorThanMaxDayInApril() {
    Date lastDayOfApril = newDate(2022, APRIL, 30);
    assert(assertIsNotNull(lastDayOfApril));

    Date outOfApril = newDate(2022, APRIL, 31);
    assert(assertIsNull(outOfApril));

    freeDate(lastDayOfApril);
    freeDate(outOfApril);
}

void itShouldNotCreateTheTwentyNinthFebruaryOfACommonYear() {
    Date d = newDate(2022, 02, 29);
    assert(assertIsNull(d));
    freeDate(d);
}

void itShouldCreateTheTwentyNinthFebruaryOfALeapYear() {
    Date d = newDate(2024, 02, 29);
    assert(assertIsNotNull(d));
    freeDate(d);
}


void itShouldCreateTheTwentyNinthFebruaryOfListOfLeapYears() {
    int years[20] = {
            1804,1816,1840,1864,1892,1924,1948,1972,1988,2012,
            2032,2068,2108,2180,2236,2268,2284,2352,2388,2400
    };
    Date list[20];
    for(int i = 0; i < 20; i += 1) {
        list[i] = newDate(years[i], 02, 29);
        assert(assertIsNotNull(list[i]));
        freeDate(list[i]);
    }
}

