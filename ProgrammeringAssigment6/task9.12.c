//
// Created by Mats on 15.11.2023.
//
#include "stdio.h"
#include "stdbool.h"
#include "math.h"

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

double strToDouble(char str[]) {
    double numb = 0;
    int i = 0;

    // Find put if the number is negativ
    bool isNegativ = false;
    if (str[0] == '-') {
        isNegativ = true;
        str = replaceString(str, "-", "");
    }
    int bigestPos = findString(str, ".");

    // Find the amout of desimal
    int desimal_lenght = 0;
    while (str[desimal_lenght+bigestPos+1] != '\0') ++desimal_lenght;
    // remove the .
    str = replaceString(str, ".", "");


    while (str[i] != '\0') {
        numb += (str[i] - '0') * pow(10, bigestPos-1);
        --bigestPos;
        ++i;
    }

    if (isNegativ) numb *=-1;
    return numb;
}

int main(void) {
    char numText[] = "-2524.1267";
    printf("%s\n", numText);
    printf("%f\n", strToDouble(numText));
}