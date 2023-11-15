//
// Created by Mats on 15.11.2023.
//
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

char* removeString(char word[], const int start, const int length) {
    int i = 0;
    while (word[i+start] != '\0') {
        word[i+start] = word[i+start+length];
        ++i;
    }
    return word;
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

char* replaceString(char source[], char s1[], char s2[]) {
    int len_s1 = lenstr(s1);
    int len_s2 = lenstr(s2);
    while (findString(source, s1) != -1){
        int s1_pos = findString(source, s1);
        source = insertString(source, s2, s1_pos);
        source = removeString(source, s1_pos+len_s2, len_s1);
    }
    return source;
}

int main(void) {
    char source[100] = "Hv*ordan *gaar d*et med* deg*!";
    char s1[] = "*";
    char s2[] = "";
    printf("%s", replaceString(source, s1,s2));
}