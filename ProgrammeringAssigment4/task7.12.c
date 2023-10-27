//
// Created by Mats on 24.10.2023.
//
#include "stdio.h"

void transposeMatrix(int i, int j, int M[i][j], int N[j][i]);
void printMatrix(int i, int j, int matrix[i][j]);

int main(void) {
    int M[4][5] = {
            {0,1,2,3,4},
            {5,6,7,8,9},
            {10,11,12,13,14},
            {15,16,17,18,19}
    };
    int N[5][4];

    transposeMatrix(4,5, M, N);

    printf("Old Matrix 4x5 \n");
    printMatrix(4,5,M);

    printf("New Matrix 5x4 \n");
    printMatrix(5,4,N);
}

void transposeMatrix(int i, int j, int M[i][j], int N[j][i]) {
    int _, _2;
    for (_ = 0; _ < i; ++_) {
        for (_2 = 0; _2 < j; ++_2) {
            N[_2][_] = M[_][_2];
        }
    }
}

void printMatrix(int i, int j, int matrix[i][j]){
    for (int _ = 0; _ < i; ++_) {
        for (int _2 = 0; _2 < j; ++_2) {
            printf("%i, ", matrix[_][_2]);
        }
        printf("\n");
    }
}