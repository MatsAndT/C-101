//
// Created by Mats on 13.11.2023. With code from the book
//
#include "stdbool.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"

struct dateAndTime {
    int hour;
    int minutes;
    int seconds;
    int day;
    int month;
    int year;
};

// Function to calculate the day of the week
struct dateAndTime dateUpdate(struct dateAndTime today) {
    struct dateAndTime tomorrow;
    int numberOfDays(struct dateAndTime d);

    if (today.day != numberOfDays(today)) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) { // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    } else { // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    tomorrow.hour = 0;
    tomorrow.minutes = 0;
    tomorrow.seconds = 0;
    return tomorrow;
}

// Function to find the number of days in a month
int numberOfDays(struct dateAndTime d) {
    int days;
    bool isLeapYear(struct dateAndTime d);
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};

    if (isLeapYear(d) && d.month == 2) {
        days = 29;
    } else {
        days = daysPerMonth[d.month - 1];
    }

    return days;
}

bool isLeapYear(struct dateAndTime d) {
    bool leapYearFlag;

    if ((d.year % 4 == 0 && d.year % 100 != 0) ||
        d.year % 400 == 0) {
        leapYearFlag = true; // It's a leap year
    } else {
        leapYearFlag = false; // Not a leap year
    }

    return leapYearFlag;
}

// Function to update the time by one second
struct dateAndTime timeUpdate(struct dateAndTime now) {
    ++now.seconds;

    if (now.seconds == 60) { // next minute
        now.seconds = 0;
        ++now.minutes;

        if (now.minutes == 60) { // next hour
            now.minutes = 0;
            ++now.hour;

            if (now.hour == 24) { // midnight
                now = dateUpdate(now);
                now.hour = 0;
            }
        }
    }

    return now;
}

// https://stackoverflow.com/a/5142028
struct dateAndTime getTime() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and date: %s", asctime (timeinfo) );
    struct dateAndTime now = {timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year};
    return now;
}

int main(void) {
    struct dateAndTime dateUpdate(struct dateAndTime today);
    struct dateAndTime currentTime, nextTime;

    // Gets the current time and date
    currentTime = getTime();

    while (1) {
        currentTime = timeUpdate(currentTime);
        printf("Updated time is %i/%i/%.2i %.2i:%.2i:%.2i\n", currentTime.day,
               currentTime.month, currentTime.year % 100, currentTime.hour,
               currentTime.minutes, currentTime.seconds);
        sleep(1);
    }
    return 0;
}