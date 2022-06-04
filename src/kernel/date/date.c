#include "date.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct Date {
    int year;
    int month;
    int day;
};

bool checkYearMonthAndDay(int year, Month month, int day);
bool dayIsInMonthOfYear(int day, Month month, int year);
int getLengthOfMonthInYear(Month month, int year);
int* getMonthsLengthInCommonYear();
int* getMonthsLengthInLeapYear();
bool yearIsLeap(int year);

bool monthIsBetweenJanuaryAndDecember(Month month);

/**
 * Date ISO 8601 : https://en.wikipedia.org/wiki/ISO_8601
 * YYYY-MM-DD -> 2022-06-28
 * @param year
 * @param month From 1 to 12 (enum Month JANUARY to DECEMBER)
 * @param day From to 1 to [28, 29 in leap year,30,31]
 * @return struct Date*
 */
Date newDate(int year, Month month, int day) {
    if(!checkYearMonthAndDay(year, month, day))
        return NULL;

    Date date = malloc(sizeof(struct Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

bool checkYearMonthAndDay(int year, Month month, int day) {
    return dayIsInMonthOfYear(day, month, year);
}

bool dayIsInMonthOfYear(int day, Month month, int year) {
    if(!monthIsBetweenJanuaryAndDecember(month)) return false;

    bool dayIsStrictPositive = day > 0;
    bool dayIsUnderMaxInMonth = day <= getLengthOfMonthInYear(month, year);
    return dayIsStrictPositive && dayIsUnderMaxInMonth;
}

bool monthIsBetweenJanuaryAndDecember(Month month) {
    return JANUARY <= month && month <= DECEMBER;
}


int getLengthOfMonthInYear(Month month, int year) {
    int* numbersOfDayIn = yearIsLeap(year)
            ? getMonthsLengthInLeapYear()
            : getMonthsLengthInCommonYear();

    int length = numbersOfDayIn[month];
    free(numbersOfDayIn);
    return length;
}

/**
 * @return array of int with the length of each month in COMMON year (28 days in february), using enum Month as index.
 * The enum Month starts at 1 so the first index is not used (value of -1).
 */
int* getMonthsLengthInCommonYear() {
    int* monthsLengths = malloc(sizeof(int) * 13); // to use index 1 to 12, as enum Month.
    monthsLengths[0] = -1;
    monthsLengths[JANUARY] = 31;
    monthsLengths[FEBRUARY] = 28;
    monthsLengths[MARCH] = 31;
    monthsLengths[APRIL] = 30;
    monthsLengths[MAY] = 31;
    monthsLengths[JUNE] = 30;
    monthsLengths[JULY] = 31;
    monthsLengths[AUGUST] = 31;
    monthsLengths[SEPTEMBER] = 30;
    monthsLengths[OCTOBER] = 31;
    monthsLengths[NOVEMBER] = 30;
    monthsLengths[DECEMBER] = 31;
    return monthsLengths;
}

/**
 * @return array of int with the length of each month in LEAP year (29 days in february), using enum Month as index.
 * The enum Month starts at 1 so the first index is not used (value of -1).
 */
int* getMonthsLengthInLeapYear() {
    int* monthsLengths = getMonthsLengthInCommonYear();
    monthsLengths[FEBRUARY] = 29;
    return monthsLengths;
}

/**
 * https://en.wikipedia.org/wiki/Leap_year#Algorithm
 */
bool yearIsLeap(int year) {
    bool yearIsNotDivisibleByFour = (year%4 != 0);
    bool yearIsNotDivisibleByHundred = (year%100 != 0);
    bool yearIsNotDivisibleByFourHundred = (year%400 != 0);

    if(yearIsNotDivisibleByFour) return false;
    else if(yearIsNotDivisibleByHundred) return true;
    else if(yearIsNotDivisibleByFourHundred) return false;
    else return true;
}

void freeDate(Date date){
    free(date);
    date = NULL;
};

int getYearOf(Date d) {
    return d->year;
}

Month getMonthOf(Date d) {
    return d->month;
}

int getDayOf(Date d) {
    return d->day;
}