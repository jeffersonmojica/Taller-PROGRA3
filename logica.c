//
// Created by JeffersonMT on 13/05/2024.
//

#include "logica.h"
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
