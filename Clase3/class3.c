/*
    * Author: Iván Maldonado
    * Topic: Ordenamiento de fila de matrices.
    * Date: 2025-08-25
*/
#include <stdio.h>

/* Constant Declarations*/
#define FILAS       (10)
#define COLUMNAS    (10)

/* Prototypes Functions*/
void ordenar(int [FILAS][COLUMNAS]);
void intercambio(int *, int *);
void mostrar_matriz(int [FILAS][COLUMNAS]);

/* Main Function */
int main() {
    int matriz[FILAS][COLUMNAS] = {
        {64, 12, 95, 38, 71, 4, 27, 83, 56, 19},
        {23, 77, 9, 41, 88, 32, 60, 5, 94, 16},
        {45, 2, 67, 91, 10, 53, 78, 29, 86, 37},
        {18, 72, 6, 49, 85, 21, 63, 34, 97, 40},
        {31, 59, 13, 76, 24, 90, 47, 8, 82, 65},
        {54, 1, 79, 35, 92, 26, 68, 43, 15, 87},
        {7, 48, 84, 20, 73, 39, 96, 52, 30, 61},
        {42, 89, 17, 74, 3, 58, 25, 91, 66, 11},
        {80, 33, 69, 14, 55, 22, 75, 46, 98, 28},
        {36, 62, 93, 50, 81, 44, 19, 57, 0, 70}
    };
    printf("::: MATRIZ ORIGINAL:::\n");
    mostrar_matriz(matriz);
    ordenar(matriz);
    printf("::: MATRIZ CON FILAS ORDENADAS:::\n");
    mostrar_matriz(matriz);
    return 0;
}

/* Functions*/
void ordenar(int matriz[FILAS][COLUMNAS]) {
    int i, j, k = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            for (k = j + 1; k < COLUMNAS; k++) {
                if (matriz[i][j] > matriz[i][k]) {
                    intercambio(&matriz[i][j], &matriz[i][k]);
                }
            }
        }
    }
}

void intercambio(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void mostrar_matriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        printf("[");
        for (j = 0; j < COLUMNAS; j++) {
            printf("%3d", matriz[i][j]);
        }
        printf(" ]\n");
    }
}
