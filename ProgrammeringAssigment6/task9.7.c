//
// Created by Mats on 15.11.2023.
//
#include "stdio.h"

int lenstr(const char text[]) {
    int i = 0;
    while (text[i] != '\0') ++i;
    return i;
}

char* insertString(char text[], char insTest[], int pos) {
    int offset = lenstr(insTest);
    int textLen = lenstr(text);
    int i = 1, j = 0;
    while (i <= textLen - pos){
        text[textLen + offset-i] = text[textLen - i];
        ++i;
    }
    while (j < offset) {
        text[pos+j] = insTest[j];
        ++j;
    }

    return text;
}

int main(void) {
    char text[150] = "Vil du ha is?12345678";
    char insText[] = "ikke ";
    int pos = 7;
    printf("%s", insertString(text, insText, pos));
}