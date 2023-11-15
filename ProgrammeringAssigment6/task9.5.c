//
// Created by Mats on 15.11.2023.
//
#include "stdio.h"

int lenstr(const char string[]) {
    int i=0;
    while (string[i] != '\0') ++i;
    return i;
}

int findString(const char string[], const char search[]) {
    int i = 0, j = 0, index = -1;
    while (string[i] != '\0' && search[j] != '\0') {
        if (string[i] == search[j]) {
            if (j==0) index = i;
            ++j;
        } else {
            j=0;
            index = -1;
        };
        ++i;
    }
    if (j != lenstr(search)) return -1;
    return index;
}

int main(void) {
    const char string[] = "hei pa deg";
    const char search[] = "e";
    printf("%i", findString(string, search));
    return 0;
}