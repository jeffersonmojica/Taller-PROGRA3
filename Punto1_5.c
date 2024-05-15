//
// Created by alejo on 14/05/2024.
//

#include "Punto1_5.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int buscarSubcadena(const char *cadena, const char *subcadena, int posicionInicio){
    if (cadena == NULL || subcadena == NULL) {
        printf("Error: Se recibió una cadena nula.\n");
        return -1;
    }

    int longitudCadena = strlen(cadena);
    int longitudSubcadena = strlen(subcadena);
    int contador = 0;

    if (longitudCadena < longitudSubcadena || posicionInicio < 0 || posicionInicio >= longitudCadena) {
        printf("Error: Parámetros de entrada inválidos.\n");
        return -1;
    }

    const char *resultado = strstr(cadena + posicionInicio, subcadena); // Buscar la subcadena a partir de la posición especificada
    while (resultado != NULL) {
        contador++;
        resultado = strstr(resultado + 1, subcadena); // Avanzar al siguiente carácter después de la ocurrencia encontrada
    }

    return contador;
}

int cadenaIniciaCon(const char *cadenaBase, const char *subcadena){
if (cadenaBase == NULL || subcadena == NULL) {
printf("Error: Se recibió una cadena nula.\n");
return -1;
}

int longitudCadenaBase = strlen(cadenaBase);
int longitudSubcadena = strlen(subcadena);

if (longitudCadenaBase < longitudSubcadena) {
printf("Error: La longitud de la cadena base es menor que la subcadena.\n");
return -1;
}

if (strncmp(cadenaBase, subcadena, longitudSubcadena) == 0) {
return 1; // La cadena base inicia con la subcadena
} else {
return 0; // La cadena base no inicia con la subcadena
}
}
