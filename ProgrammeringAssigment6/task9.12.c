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

float strToFloat(char str[]) {
    float numb = 0;
    int i = 0;
    bool isNegativ = false;
    if (str[0] == '-') {
        isNegativ = true;
        str = replaceString(str, "-", "");
    }
    int bigestPos = findString(str, ".");


    while (str[i] != '\0') {
        double current_numb;
        switch (str[i]) {
            case '1':
                current_numb = 1;
                break;
            case '2':
                current_numb = 2;
                break;
            case '3':
                current_numb = 3;
                break;
            case '4':
                current_numb = 4;
                break;
            case '5':
                current_numb = 5;
                break;
            case '6':
                current_numb = 6;
                break;
            case '7':
                current_numb = 7;
                break;
            case '8':
                current_numb = 8;
                break;
            case '9':
                current_numb = 9;
                break;
        }
        numb += current_numb * pow(10, bigestPos-1);
        --bigestPos;
        ++i;
    }




    if (isNegativ) numb *=-1;
    printf("%s\n", str);
    return numb;
}

int main(void) {
    char numText[] = "-254.125";
    printf("%f", strToFloat(numText));
}