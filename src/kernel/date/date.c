#include "date.h"
#include <stdlib.h>

struct Date {
    int year;
    int month;
    int day;
};

/**
 * Date ISO 8601 : https://en.wikipedia.org/wiki/ISO_8601
 * YYYY-MM-DD -> 2022-06-28
 * @param year
 * @param month From 1 to 12
 * @param day From to 1 to 31
 * @return struct Date*
 */
Date newDate(int year, Month month, int day) {
    Date date = malloc(sizeof(struct Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void freeDate(Date date){
    free(date);
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