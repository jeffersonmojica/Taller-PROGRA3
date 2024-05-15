#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Punto1_5.h"
#include "ChangeString.h"
int main() {
    char cadena[101]; // Tamaño para la cadena base
    char subcadena[50]; // Tamaño para la subcadena
    int opcion, posicionInicio;
    int inicio;
    char c;

    do {
        printf("\nMenu de opciones:\n");

        printf("1. Buscar todas las ocurrencias de una subcadena\n");
        printf("4.Función que reemplaza todas las ocurrencias de un carácter por otro \n");
        printf("5. Validar si una cadena inicia con otra\n");

        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Error: Se debe ingresar un número.\n");
            while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada

        if (opcion < 1 || opcion > 9) {
            printf("Error: Opción fuera de rango.\n");
            continue;
        }

        printf("Ingrese la cadena base: ");
        fgets(cadena, sizeof(cadena), stdin);
        cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea

        switch (opcion) {
            case 1:
                printf("Ingrese la subcadena a buscar: ");
                scanf("%s", subcadena);
                while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
                printf("Introduzca la posición desde donde iniciar la búsqueda: ");
                scanf("%d", &posicionInicio);
                while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
                printf("Número total de ocurrencias encontradas: %d\n", searchSubstring(cadena, subcadena, posicionInicio));
                break;
            case 4:
                ReplaceCharacters();
                break;

            case 5:
                printf("Ingrese la cadena a verificar si inicia con: ");
                fgets(subcadena, sizeof(subcadena), stdin);
                subcadena[strcspn(subcadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                inicio = stringStartWith(cadena, subcadena);
                printf("%d\n", inicio);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 0);



    return 0;
}

