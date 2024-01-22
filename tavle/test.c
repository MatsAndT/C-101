//
// Created by Mats on 04.12.2023.
//
#include <stdio.h>

int trial(int n) {
    int result;

    if (n == 0) {
        result =  1;
    } else {
        result = n*trial(n - 1);
    }
    return result;
}



int main() {
    printf("%i", trial(5));
    return 0;
}