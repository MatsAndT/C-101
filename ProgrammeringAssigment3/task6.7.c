//
// Created by Mats on 24.10.2023.
//
#include "stdio.h"

int main(void) {
    const int n = 150;
    int index, j;
    int P[n];

    // steg 1, sett alle tall over index 2 til 0
    for (index = 2; index < n; ++index) {
        P[index] = 0;
    }

    //steg 2, set index = 2
    index = 2;
    //steg 3,  if i > n, da stopper algorytmen
    while (index < n) {
        // steg 4, hvis Pi er 0 så den den prim
        if (P[index] == 0) {
            // steg 5,  for alle posetive tall verdier av j, som index * j <= n, sett P[index * j] to 1
            for (j = 2; index * j <=n; ++j) {
                P[index * j] = 1;
            }
        }
        // steg 6, økte index
        ++index;
    }

    for (index = 0; index < n; ++index) {
        if (P[index] == 0) printf("%i er et primtal \n", index);
    }
}