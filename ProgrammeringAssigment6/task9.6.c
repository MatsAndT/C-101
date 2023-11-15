//
// Created by Mats on 15.11.2023.
//
#include "stdio.h"

char* removeString(char word[], const int start, const int length) {
    int i = 0;
    while (word[i+start] != '\0') {
        word[i+start] = word[i+start+length];
        ++i;
    }
    return word;
}

int main(void) {

    char a[] = {"123456789abcdef"};
    printf("%s", removeString(a, 2,3));
}