#ifndef CLANG_POKEDEX_DATE_H
#define CLANG_POKEDEX_DATE_H

typedef struct Date* Date;
typedef enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;
Date newDate(int year, Month month, int day);
void freeDate(Date date);
Date dateCopy(Date d);

int getYearOf(Date d);
Month getMonthOf(Date d);
int getDayOf(Date d);

#endif //CLANG_POKEDEX_DATE_H
