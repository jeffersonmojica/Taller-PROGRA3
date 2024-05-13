//
// Created by JeffersonMT on 13/05/2024.
//

#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* obtenerSubcadena(const char* cadena, int inicio, int fin) {
    if (cadena == NULL || inicio < 0 || fin < 0 || inicio > strlen(cadena) || fin > strlen(cadena)) {
        return NULL; // Validamos los parámetros de entrada
    }

    char* subcadena;
    int longitud;

    if (fin == 0) {
        longitud = strlen(cadena) - inicio;
        subcadena = (char*)malloc((longitud + 1) * sizeof(char));
        strncpy(subcadena, cadena + inicio, longitud);
    } else if (inicio > fin) {
        longitud = inicio - fin + 1;
        subcadena = (char*)malloc((longitud + 1) * sizeof(char));
        for (int i = inicio, j = 0; i >= fin; i--, j++) {
            subcadena[j] = cadena[i];
        }
        subcadena[longitud] = '\0';
    } else {
        longitud = fin - inicio + 1;
        subcadena = (char*)malloc((longitud + 1) * sizeof(char));
        strncpy(subcadena, cadena + inicio, longitud);
    }

    subcadena[longitud] = '\0'; // Agregamos el terminador de cadena
    return subcadena;
}

char* obtenerDiferencia(const char* cadena1, const char* cadena2) {
    if (cadena1 == NULL || cadena2 == NULL) {
        return NULL; // Validación de entradas nulas
    }

    // Verificar si las cadenas contienen caracteres repetidos
    int caracteres[256] = {0};
    for (int i = 0; i < strlen(cadena2); i++) {
        caracteres[(int)cadena2[i]]++;
    }

    for (int i = 0; i < strlen(cadena1); i++) {
        if (caracteres[(int)cadena1[i]] > 0) {
            return NULL; // Caracteres repetidos, no se puede calcular la diferencia
        }
    }

    // Calcular la diferencia entre las cadenas
    char* diferencia = (char*)malloc((strlen(cadena1) + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(cadena1); i++) {
        if (!strchr(cadena2, cadena1[i])) {
            diferencia[j++] = cadena1[i];
        }
    }
    diferencia[j] = '\0';

    return diferencia;
}

