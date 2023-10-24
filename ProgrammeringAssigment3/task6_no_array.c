//
// Created by Mats on 11.10.2023.
//

#include "stdio.h"

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