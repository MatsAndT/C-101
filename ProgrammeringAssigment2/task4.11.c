//
// Created by Mats on 06.10.2023.
//

#include "stdio.h"

int main(void) {
    int input;
    int val = 0;
    printf("Hva er verdien? Skriv et rent tall!");
    scanf("%i", &input);

    while (input) {
        printf("%d ", input % 10); // https://stackoverflow.com/a/3118505
        val = val + input % 10;
        input /= 10;
        if (input) printf("+ ");
    }

    printf("= %d", val);
    return 0;
}