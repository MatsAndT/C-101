//
// Created by Mats on 07.11.2023.
//
#include "stdio.h"

struct Date {
    int day;
    int month;
    int year;
};

int f(struct Date d) {
    if (d.month <= 2) {
        return d.year - 1;
    } else {
        return d.year;
    }
}

int g(struct Date d) {
    if (d.month <= 2) {
        return d.month + 13;
    } else {
        return d.month + 1;
    }
}

int calc_diff(struct Date d1, struct Date d2) {
    int f1 = 1461 * f(d1) / 4 + 153 * g(d1) / 5 + d1.day;
    int f2 = 1461 * f(d2) / 4 + 153 * g(d2) / 5 + d2.day;

    return f2 - f1;
}

struct Date fix_year(struct Date d) {
    // Hvis datoen er over 1 mars 1900 så skjer det ikke noe
    if (d.year > 1900) {
        return d;
    } else if (d.year == 1900) {
        if (d.month <= 2) {
            return d;
        }
    }

    // Hvis datoen er over mars 1 1800 så legger vi til en
    if (d.year > 1800) {
        struct Date fix_d = {d.day, d.month, d.year++};
        return fix_d;
    } else if (d.year == 1800) {
        if (d.month <= 2) {
            struct Date fix_d = {d.day, d.month, d.year++};
            return  fix_d;
        }
    }

    struct Date fix_d = {d.day, d.month, d.year+=2};
    return fix_d;
}

struct Date get_date() {
    printf("Type a date in this format dd/mm/yyyy, dont11 type /, but press enter after each number, the date must be after 28/02/1800!\n");
    int day, month, year;
    scanf("%i %i %i", &day, &month, &year);
    struct Date d = {day, month, year};

    return d;
}

int main(void) {
    struct Date d1 = get_date();
    struct Date d2 = get_date();

    d1 = fix_year(d1);
    d2 = fix_year(d2);

    int diff = calc_diff(d1, d2);
    printf("Diff: %i", diff);
    return 0;
}