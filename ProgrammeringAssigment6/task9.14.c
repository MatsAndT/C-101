//
// Created by Mats on 21.11.2023.
//
#include "stdio.h"

char *intToStr(char strNum[40], int numb) {
    int numLen = 0;
    //char strNum[40] = "";

    int _numb = numb;
    while (_numb) {
        ++numLen;
        _numb /= 10;
    }

    if (numb < 0) {
        numb *= -1;
        ++numLen;
        strNum[0] = '-';
    }

    while (numb) {
        int curNum = numb % 10;
        numb /= 10;
        strNum[numLen-1] = curNum + '0';
        --numLen;
    }
    //printf("%s\n", strNum);
    return strNum;
}

int main(void) {
    int numb = -3422;

    char strNum[40];
    intToStr(strNum, numb);
    printf("In int: %i\n", numb);
    printf("In string: %s\n", strNum);
}