//
// Created by Mats on 27.11.2023.
//
#include "stdio.h"

struct entry {
    int value;
    struct entry *next;
    struct entry *previous;
};

struct entry doEntry(int value, struct entry *next, struct entry *previous) {
    struct entry e;
    e.value = value;
    e.next = next;
    e.previous = previous;

    return e;
}

void insertEntry(struct entry *current, struct entry *previous, struct entry *next) {
    previous->next = current;
    next->previous = current;
}

int main(void) {
    struct entry e, e1, e2, e3, e4, e5, e6, e3_1;
    e1 = doEntry(1, &e2, (struct entry *) 0);
    e2 = doEntry(2, &e3, &e1);
    e3 = doEntry(3, &e4, &e2);
    e4 = doEntry(4, &e5, &e3);
    e5 = doEntry(5, &e6, &e4);
    e6 = doEntry(6, (struct entry *) 0, &e5);

    insertEntry(&e3_1, &e3, &e4);
    e3_1 = doEntry(31, &e4, &e3);

    e = e1;
    while (1) {
        printf("value: %i\n", e.value);
        // Hvis denne ikke er her, men i while, så vil ikke den stste e6 bli printet \/
        if (e.next == (struct entry *) 0) break;
        e = *e.next;
    }
    e = e6;
    printf("\n");
    while (1) {
        printf("value: %i\n", e.value);
        // Hvis denne ikke er her, men i while, så vil ikke den stste e1 bli printet \/
        if (e.previous == (struct entry *) 0) break;
        e = *e.previous;
    }
    return 1;
}