//
// Created by Mats on 06.10.2023.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    printf("Hva vil du ha foran ! ?");
    scanf("%i",&i);
    int val = 1;
    for (; i!=1; --i) {
        printf("%i x ", i);
        val = val * i;
    }
    printf("%i = %i", 1, val);
    return 0;
}
