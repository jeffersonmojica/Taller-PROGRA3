#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char opcionStr[10];
    int opcion;

    do {
        mostrarMenu();
        fgets(opcionStr, sizeof(opcionStr), stdin);
        opcionStr[strcspn(opcionStr, "\n")] = '\0';

        if (isdigit(opcionStr[0])) {
            opcion = atoi(opcionStr);
            manejarOpcion(opcion);
        } else {
            printf("Error: Ingrese una opcion numerica valida.\n");
        }
    } while (1);

    return 0;
}