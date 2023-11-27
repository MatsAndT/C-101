//
// Created by Mats on 27.11.2023.
//
#include "stdio.h"

struct entry {
    int value;
    struct entry *next;
};

struct entry doEntry(int value, struct entry *next) {
    struct entry e;
    e.value = value;
    e.next = next;

    return e;
}

void insertEntry(struct entry *current, struct entry *next) {
    current->next = next;
}

int main(void) {
    struct entry e, e1, e2, e3, e4, e5, e6, e2_1;
    e1 = doEntry(1, &e2);
    e2 = doEntry(2, &e3);
    e3 = doEntry(3, &e4);
    e4 = doEntry(4, &e5);
    e5 = doEntry(5, &e6);
    e6 = doEntry(6, (struct entry *) 0);

    insertEntry(&e2, &e2_1);
    e2_1 = doEntry(21, &e3);


    e = e1;

    while (1) {
        printf("value: %i\n", e.value);
        // Hvis denne ikke er her, men i while, så vil ikke den stste e6 bli printet \/
        if (e.next == (struct entry *) 0) break;
        e = *e.next;
    }
    return 1;
}