//
// Created by Mats on 11.10.2023.
//

#include "stdio.h"
#include "math.h"

char* intToStr(int n) {
    switch (n) {
        case 0:
            return "zero";
            break;
        case 1:
            return "one";
            break;
        case 2:
            return "two";
            break;
        case 3:
            return "three";
            break;
        case 4:
            return "four";
            break;
        case 5:
            return "five";
            break;
        case 6:
            return "six";
            break;
        case 7:
            return "seven";
            break;
        case 8:
            return "ate";
            break;
        case 9:
            return "nie";
            break;
        default:
            return "wtf";
            break;
    }
}

int main(void) {
    int num;
    printf("Hva er nummeret:");
    scanf("%i", &num);
    char* inStr = "";

    // For å fikse hvis det blir langt inn et negativt tall
    if (num < 0) {
        num = num * -1;
    }
    int flipt;

    while (num) {
        flipt = flipt + (num %10);
        flipt = flipt*10;
        num /= 10;
    }
    flipt /=10;
    while (flipt) {
        int n = flipt % 10;
        flipt /= 10;

        switch (n) {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("ate ");
                break;
            case 9:
                printf("nie ");
                break;
            default:
                printf("wtf ");
                break;
        }
    }

    printf("%s", inStr);

    return 0;
}