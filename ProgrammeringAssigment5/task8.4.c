//
// Created by Mats on 08.11.2023.
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

int fix_year(struct Date d) {
    // Hvis datoen er over 1 mars 1900 så skjer det ikke noe
    if (d.year > 1900) {
        return 0;
    } else if (d.year == 1900) {
        if (d.month <= 2) {
            return 0;
        }
    }

    // Hvis datoen er over mars 1 1800 så legger vi til en
    if (d.year > 1800) {
        return 1;
    } else if (d.year == 1800) {
        if (d.month <= 2) {
            return 1;
        }
    }

    return 2;
}

struct Date get_date() {
    printf("Type a date in this format dd/mm/yyyy, the date must be after 28/02/1700!\n");
    int day, month, year;
    scanf("%i/%i/%i", &day, &month, &year);
    struct Date d = {day, month, year};

    return d;
}

const char* find_day(struct Date d) {
    int f1 = 1461 * f(d) / 4 + 153 * g(d) / 5 + d.day;
    f1 += fix_year(d);
    int f = f1 - 621049;
    int day_nr = f % 7;
    char *day_str;

    switch (day_nr) {
        case 0:
            day_str = "Sunday";
            break;
        case 1:
            day_str = "Monday";
            break;
        case 2:
            day_str = "Tuesday";
            break;
        case 3:
            day_str = "Wednesday";
            break;
        case 4:
            day_str = "Thursday";
            break;
        case 5:
            day_str = "Friday";
            break;
        case 6:
            day_str = "Saturday";
            break;
        default:
            day_str = "ERROR";
            break;
    }
    return day_str;
}

int main(void) {
    struct Date d = get_date();

    printf("The day of the week is %s", find_day(d));
    return 0;
}