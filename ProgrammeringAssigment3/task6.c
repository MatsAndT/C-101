//
// Created by Mats on 11.10.2023.
//

#include "stdio.h"
#include "math.h"

int get_len(int val) {
    // https://stackoverflow.com/a/3068426
    return ( val==0 ) ? 1 : (int)log10(val)+1;
}

int main(void) {
    int num;
    printf("Hva er nummeret:");
    scanf("%i", &num);

    // For å fikse hvis det blir langt inn et negativt tall
    if (num < 0) {
        num = num * -1;
    }

    int num_len = get_len(num);
    int num_list[10000] = {};

    int i = num_len - 1;

    while (num) {
        num_list[i] = num % 10;
        num /= 10;
        i--;
    }

    for (int p=0; p<num_len; p++) {
        switch (num_list[p]) {
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
    };
    return 0;
}