#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
int main() {
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        manejarOpcion(opcion);
    } while (opcion != 0);

    return 0;
}*/

int main() {
    char opcionStr[10];
    int opcion;

    do {
        mostrarMenu();
        fgets(opcionStr, sizeof(opcionStr), stdin);
        opcionStr[strcspn(opcionStr, "\n")] = '\0'; // Eliminar el salto de línea al final

        if (isdigit(opcionStr[0])) { // Verificar si la primera letra es un dígito
            opcion = atoi(opcionStr);
            manejarOpcion(opcion);
        } else {
            printf("Error: Ingrese una opcion numerica valida.\n");
        }
    } while (1);

    return 0;
}