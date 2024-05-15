//
// Created by JeffersonMT on 14/05/2024.
//

#include "Programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void showMenu() {
    printf("\n---------------- Programa de Subcadenas ----------------\n");
    printf("1. Obtener subcadena\n");
    printf("2. Obtener diferencia entre cadenas\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void handleOption(int option) {
    switch (option) {
        case 1: {
            char string[100];
            int start, end;
            char* substring;

            clearBuffer();
            printf("Ingrese la cadena: ");
            fgets(string, sizeof(string), stdin);
            string[strcspn(string, "\n")] = '\0';

            if (string[0] == '\0') {
                printf("Error: La cadena no puede estar vacia.\n");
                break;
            }

            int length = strlen(string);
            printf("La cadena tiene %d caracteres.\n", length);

            do {
                printf("Ingrese el inicio del rango (entre 0 y %d): ", length - 1);
                char startStr[10];
                fgets(startStr, sizeof(startStr), stdin);
                start = atoi(startStr);
                if (start < 0 || start >= length) {
                    printf("Error: Ingrese un inicio dentro del rango valido.\n");
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Ingrese el fin del rango (entre %d y %d): ", start + 1, length);
                char endStr[10];
                fgets(endStr, sizeof(endStr), stdin);
                end = atoi(endStr);
                if (end <= start || end > length) {
                    printf("Error: Ingrese un fin dentro del rango valido.\n");
                } else {
                    break;
                }
            } while (1);

            substring = getSubstring(string, start, end);
            if (substring != NULL) {
                printf("La subcadena es: %s\n", substring);
                free(substring);
            } else {
                printf("Error: El rango especificado es invalido.\n");
            }

            break;
        }

        case 2: {
            char string1[100];
            char string2[100];
            char* difference;

            clearBuffer();
            printf("Ingrese la primera cadena: ");
            fgets(string1, sizeof(string1), stdin);
            string1[strcspn(string1, "\n")] = '\0';

            if (string1[0] == '\0') {
                printf("Error: La primera cadena no puede estar vacia.\n");
                break;
            }

            clearBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(string2, sizeof(string2), stdin);
            string2[strcspn(string2, "\n")] = '\0';

            if (string2[0] == '\0') {
                printf("Error: La segunda cadena no puede estar vacia.\n");
                break;
            }

            difference = getDifference(string1, string2);
            if (difference != NULL) {
                printf("La diferencia entre las cadenas es: %s\n", difference);
                free(difference);
            } else {
                printf("No se puede calcular la diferencia debido a caracteres repetidos en las cadenas: ");
                for (int i = 0; i < strlen(string1); i++) {
                    for (int j = 0; j < strlen(string2); j++) {
                        if (string1[i] == string2[j]) {
                            printf("%c ", string1[i]);
                        }
                    }
                }
                printf("\n");
            }

            break;
        }

        case 0:
            printf("Saliendo del programa.\n");
            exit(0);
        default:
            printf("Opcion invalida.\n");
    }
}

char* getSubstring(const char* string, int start, int end) {
    if (string == NULL || start < 0 || end < 0 || start > strlen(string) || end > strlen(string)) {
        return NULL;
    }

    char* substring;
    int length;

    if (end == 0) {
        length = strlen(string) - start;
        substring = (char*)malloc((length + 1) * sizeof(char));
        strncpy(substring, string + start, length);
    } else if (start > end) {
        length = start - end + 1;
        substring = (char*)malloc((length + 1) * sizeof(char));
        for (int i = start, j = 0; i >= end; i--, j++) {
            substring[j] = string[i];
        }
        substring[length] = '\0';
    } else {
        length = end - start + 1;
        substring = (char*)malloc((length + 1) * sizeof(char));
        strncpy(substring, string + start, length);
    }

    substring[length] = '\0';
    return substring;
}

char* getDifference(const char* string1, const char* string2) {
    if (string1 == NULL || string2 == NULL) {
        return NULL;
    }

    int characters[256] = {0};
    for (int i = 0; i < strlen(string2); i++) {
        characters[(int)string2[i]]++;
    }

    for (int i = 0; i < strlen(string1); i++) {
        if (characters[(int)string1[i]] > 0) {
            return NULL;
        }
    }

    // Calculate the difference between strings
    char* difference = (char*)malloc((strlen(string1) + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (!strchr(string2, string1[i])) {
            difference[j++] = string1[i];
        }
    }
    difference[j] = '\0';

    return difference;
}
