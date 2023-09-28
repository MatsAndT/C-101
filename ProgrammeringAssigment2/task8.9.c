//
// Created by Mats on 28.09.2023.
//

#include <stdio.h>
#include <math.h>

int Next_multiple(int i, int j) {
    return i + j - i % j;
}

int main(void) {
    printf("i = 365, j = 7: %d\n", Next_multiple(365, 7));
    printf("i = 12258, j = 23: %d\n", Next_multiple(12258, 23));
    printf("i = 996, j = 4: %d\n", Next_multiple(996, 4));
    return 0;
}
