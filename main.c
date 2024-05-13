#include "ui.h"
#include <stdio.h>

int main() {
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        manejarOpcion(opcion);
    } while (opcion != 0);

    return 0;
}
