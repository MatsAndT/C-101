//
// Created by Mats on 08.11.2023.
//

#include "stdio.h"

struct Time {
    int hour;
    int minute;
    int second;
};

struct Time elapsed_time(struct Time time1, struct Time time2);
int time_to_timestamp(struct Time t);
struct Time timestamp_to_time(int s);
struct Time get_time_from_user();

int main(void) {
    printf("You are now going to type to times in the same day, first the first time then a time after!\n");
    struct Time t1 = get_time_from_user();
    struct Time t2 = get_time_from_user();

    struct Time diff_t = elapsed_time(t1, t2);

    printf("Diff %i:%i:%i", diff_t.hour, diff_t.minute, diff_t.second);
    return 0;
}

struct Time elapsed_time(struct Time time1, struct Time time2) {
    int t1_timestamp = time_to_timestamp(time1);
    int t2_timestamp = time_to_timestamp(time2);

    int diff_t_timestamp;
    if (t1_timestamp > t2_timestamp) {
        diff_t_timestamp = t1_timestamp - t2_timestamp;
    } else {
        diff_t_timestamp = t2_timestamp - t1_timestamp;
    }

    struct Time diff_t = timestamp_to_time(diff_t_timestamp);
    return diff_t;
}

struct Time get_time_from_user() {
    printf("Write a time in this format HH:MM:SS\n");
    int hours, minutes, seconds;
    scanf("%i:%i:%i", &hours, &minutes, &seconds);
    struct Time t = {hours, minutes, seconds};
    return t;
}

int time_to_timestamp(struct Time t) {
    int s = 0;
    s += t.hour * 60 * 60;
    s += t.minute * 60;
    s += t.second;

    return s;
}

struct Time timestamp_to_time(int s) {
    struct Time t;
    t.hour = s / 3600;
    s = s % 3600;
    t.minute = s / 60;
    s = s % 60;
    t.second = s;

    return t;
};