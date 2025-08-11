#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGHT (30)

void invertir_string(char *, char*);
int contador_vocales(char *);
int es_palindromo(char *, char*);

int main() {
    char entrada[(MAX_TEXT_LENGHT + 1)], salida[(MAX_TEXT_LENGHT + 1)];
    printf("Ingrese un texto(Máximo %d caracteres): ", MAX_TEXT_LENGHT);
    fgets(entrada, (MAX_TEXT_LENGHT + 1), stdin);
    int i = 0;
    while (entrada[i] != '\n') {
        i++;
    }
    entrada[i] = '\0';
    invertir_string(entrada, salida);
    printf("-----------------\n");
    printf("String Invertido: %s\n", salida);
    printf("Numero de vocales: %d\n", contador_vocales(salida));
    if (es_palindromo(entrada, salida)) {
        printf("Es palindromo: Si.\n");
    } else {
        printf("Es palindromo: No.\n");
    }
    return 0;
}

void invertir_string(char * entrada, char* salida) {
    int i, tamano_entrada = strlen(entrada);
    char entrada2[tamano_entrada+1];
    char aux;
    strcpy(entrada2, entrada);
    for (i = 0; i < tamano_entrada / 2; i++) {
        aux = entrada2[i];
        entrada2[i] = entrada2[tamano_entrada - 1 - i];
        entrada2[tamano_entrada - 1 - i] = aux;
    }
    strcpy(salida, entrada2);

}

int contador_vocales(char * entrada) {

    int i, totalVocales = 0;
    for (i = 0; i < strlen(entrada); i++) {
        if (entrada[i] == 'A' || entrada[i] == 'E' || entrada[i] == 'I' || entrada[i] == 'O' || entrada[i] == 'U' ||
            entrada[i] == 'a' || entrada[i] == 'e' || entrada[i] == 'i' || entrada[i] == 'o' || entrada[i] == 'u') {
            totalVocales++;
        }
    }
    return totalVocales;
}

int es_palindromo(char * entrada, char* salida) {

    int esPalindromo = 0;
    if (strncmp(entrada, salida, MAX_TEXT_LENGHT + 1) == 0) {
        esPalindromo = 1;
    }
    return esPalindromo;
}