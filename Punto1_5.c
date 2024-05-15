//
// Created by alejo on 14/05/2024.
//

#include "Punto1_5.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int searchSubstring(const char *chain, const char *subChain, int positionStart){
    if (chain == NULL || subChain == NULL) {
        printf("Error: Se recibió una cadena nula.\n");
        return -1;
    }

    int chainlength = strlen(chain);
    int substringLength = strlen(subChain);
    int counter = 0;

    if (chainlength < substringLength || positionStart < 0 || positionStart >= chainlength) {
        printf("Error: Parámetros de entrada inválidos.\n");
        return -1;
    }

    const char *result = strstr(chain + positionStart, subChain); // Buscar la subChain a partir de la posición especificada
    while (result != NULL) {
        counter++;
        result = strstr(result + 1, subChain); // Avanzar al siguiente carácter después de la ocurrencia encontrada
    }

    return counter;
}

int stringStartWith(const char *chainBase, const char *subChain){
if (chainBase == NULL || subChain == NULL) {
printf("Error: Se recibió una cadena nula.\n");
return -1;
}

int lengthChainBase = strlen(chainBase);
int lengthSubString = strlen(subChain);

if (lengthChainBase < lengthSubString) {
printf("Error: La longitud de la cadena base es menor que la sub cadena.\n");
return -1;
}

if (strncmp(chainBase, subChain, lengthSubString) == 0) {
return 1; // La chain base inicia con la subChain
} else {
return 0; // La chain base no inicia con la subChain
}
}
