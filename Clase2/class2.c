/*
*   Author: Iván Maldonado Rodríguez
*   Date: 2025.08.18
*   Topic: Ordenamiento de texto (Ascendente).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void ordenar(char *);
void ingresarTexto(char *, int);

/* Main Program */
int main() {
    char codigo_texto[] = "FZJYQKOMWUXVCPRSTBHLADGNIE";
    char nuevo_texto[31];
    printf("* Texto sin ordenar (Default): %s\n", codigo_texto);
    ordenar(codigo_texto);
    printf("******************************************\n");
    printf("* Ingrese un nuevo texto (Hasta 31 caracteres): ");
    ingresarTexto(nuevo_texto, 31);
    ordenar(nuevo_texto);
    return 0;
}

/* Functions */
void ordenar(char * texto) {
    int i, j;
    char aux;
    int size = strlen(texto);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (texto[j] > texto[i]) {
                aux = texto[i];
                texto[i] = texto[j];
                texto[j] = aux;
            }
        }
    }
    printf("* Texto ordenado: %s\n", texto);
}

void ingresarTexto(char * texto, int size) {
    char character;
    int i = 0;
    while ((character = getchar()) != '\n') {
        if (i < size - 1) {
            texto[i] = character;
            i++;
        }
    } 
    texto[i] = '\0';
}