//
// Created by JeffersonMT on 13/05/2024.
//

/*
#include "ui.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu() {
    printf("\n---------------- Programa de Subcadenas ----------------\n");
    printf("1. Obtener subcadena\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void manejarOpcion(int opcion) {
    switch (opcion) {
        case 1: {
            char cadena[100]; // Se define una cadena de 100 caracteres
            int inicio, fin;
            char* subcadena;

            limpiarBuffer(); // Limpiar el buffer antes de leer la cadena
            printf("Ingrese la cadena: ");
            fgets(cadena, sizeof(cadena), stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea al final

            int longitud = strlen(cadena);
            printf("La cadena tiene %d caracteres.\n", longitud);

            do {
                printf("Ingrese el inicio del rango (entre 0 y %d): ", longitud - 1);
                if (scanf("%d", &inicio) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (inicio < 0 || inicio >= longitud) {
                    printf("Error: Ingrese un inicio dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Ingrese el fin del rango (entre %d y %d): ", inicio + 1, longitud);
                if (scanf("%d", &fin) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (fin <= inicio || fin > longitud) {
                    printf("Error: Ingrese un fin dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            subcadena = obtenerSubcadena(cadena, inicio, fin);
            if (subcadena != NULL) {
                printf("La subcadena es: %s\n", subcadena);
                free(subcadena); // Liberar la memoria asignada a la subcadena
            } else {
                printf("Error: El rango especificado es invalido.\n");
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

*/

/*

#include "ui.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu() {
    printf("\n---------------- Programa de Subcadenas ----------------\n");
    printf("1. Obtener subcadena\n");
    printf("2. Comparar cadenas\n");
    printf("3. Concatenar cadenas\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void manejarOpcion(int opcion) {
    switch (opcion) {
        case 1: {
            char cadena[100];
            int inicio, fin;
            char* subcadena;

            limpiarBuffer();
            printf("Ingrese la cadena: ");
            fgets(cadena, sizeof(cadena), stdin);
            cadena[strcspn(cadena, "\n")] = '\0';

            int longitud = strlen(cadena);
            printf("La cadena tiene %d caracteres.\n", longitud);

            do {
                printf("Ingrese el inicio del rango (entre 0 y %d): ", longitud - 1);
                if (scanf("%d", &inicio) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (inicio < 0 || inicio >= longitud) {
                    printf("Error: Ingrese un inicio dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Ingrese el fin del rango (entre %d y %d): ", inicio + 1, longitud);
                if (scanf("%d", &fin) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (fin <= inicio || fin > longitud) {
                    printf("Error: Ingrese un fin dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            subcadena = obtenerSubcadena(cadena, inicio, fin);
            if (subcadena != NULL) {
                printf("La subcadena es: %s\n", subcadena);
                free(subcadena);
            } else {
                printf("Error: El rango especificado es invalido.\n");
            }

            break;
        }
        case 2: {
            char cadena1[100];
            char cadena2[100];

            limpiarBuffer();
            printf("Ingrese la primera cadena: ");
            fgets(cadena1, sizeof(cadena1), stdin);
            cadena1[strcspn(cadena1, "\n")] = '\0';

            limpiarBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(cadena2, sizeof(cadena2), stdin);
            cadena2[strcspn(cadena2, "\n")] = '\0';

            if (strcmp(cadena1, cadena2) == 0) {
                printf("Las cadenas son iguales.\n");
            } else {
                printf("Las cadenas son diferentes.\n");
            }

            break;
        }
        case 3: {
            char cadena1[100];
            char cadena2[100];
            char cadenaConcatenada[200];

            limpiarBuffer();
            printf("Ingrese la primera cadena: ");
            fgets(cadena1, sizeof(cadena1), stdin);
            cadena1[strcspn(cadena1, "\n")] = '\0';

            limpiarBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(cadena2, sizeof(cadena2), stdin);
            cadena2[strcspn(cadena2, "\n")] = '\0';

            strcpy(cadenaConcatenada, cadena1);
            strcat(cadenaConcatenada, cadena2);

            printf("La concatenacion de las cadenas es: %s\n", cadenaConcatenada);

            break;
        }
        case 0:
            printf("Saliendo del programa.\n");
            exit(0);
        default:
            printf("Opcion invalida.\n");
    }
}
*/
/*
#include "ui.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu() {
    printf("\n---------------- Programa de Subcadenas ----------------\n");
    printf("1. Obtener subcadena\n");
    printf("2. Obtener diferencia entre cadenas\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void manejarOpcion(int opcion) {
    switch (opcion) {
        case 1: {
            char cadena[100]; // Se define una cadena de 100 caracteres
            int inicio, fin;
            char* subcadena;

            limpiarBuffer(); // Limpiar el buffer antes de leer la cadena
            printf("Ingrese la cadena: ");
            fgets(cadena, sizeof(cadena), stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea al final

            int longitud = strlen(cadena);
            printf("La cadena tiene %d caracteres.\n", longitud);

            do {
                printf("Ingrese el inicio del rango (entre 0 y %d): ", longitud - 1);
                if (scanf("%d", &inicio) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (inicio < 0 || inicio >= longitud) {
                    printf("Error: Ingrese un inicio dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Ingrese el fin del rango (entre %d y %d): ", inicio + 1, longitud);
                if (scanf("%d", &fin) != 1) {
                    printf("Error: Ingrese un numero valido.\n");
                    limpiarBuffer();
                } else if (fin <= inicio || fin > longitud) {
                    printf("Error: Ingrese un fin dentro del rango valido.\n");
                    limpiarBuffer();
                } else {
                    break;
                }
            } while (1);

            subcadena = obtenerSubcadena(cadena, inicio, fin);
            if (subcadena != NULL) {
                printf("La subcadena es: %s\n", subcadena);
                free(subcadena); // Liberar la memoria asignada a la subcadena
            } else {
                printf("Error: El rango especificado es invalido.\n");
            }

            break;
        }

        case 2: {
            char cadena1[100];
            char cadena2[100];
            char* diferencia;

            limpiarBuffer();
            printf("Ingrese la primera cadena: ");
            fgets(cadena1, sizeof(cadena1), stdin);
            cadena1[strcspn(cadena1, "\n")] = '\0'; // Eliminar el salto de línea al final

            limpiarBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(cadena2, sizeof(cadena2), stdin);
            cadena2[strcspn(cadena2, "\n")] = '\0'; // Eliminar el salto de línea al final

            // Llamada a la función para obtener la diferencia entre cadenas
            diferencia = obtenerDiferencia(cadena1, cadena2);
            if (diferencia != NULL) {
                printf("La diferencia entre las cadenas es: %s\n", diferencia);
                free(diferencia);
            } else {
                // Buscar y mostrar caracteres repetidos
                printf("No se puede calcular la diferencia debido a caracteres repetidos en las cadenas: ");
                for (int i = 0; i < strlen(cadena1); i++) {
                    for (int j = 0; j < strlen(cadena2); j++) {
                        if (cadena1[i] == cadena2[j]) {
                            printf("%c ", cadena1[i]);
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
*/
#include "ui.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu() {
    printf("\n---------------- Programa de Subcadenas ----------------\n");
    printf("1. Obtener subcadena\n");
    printf("2. Obtener diferencia entre cadenas\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void manejarOpcion(int opcion) {
    switch (opcion) {
        case 1: {
            char cadena[100]; // Se define una cadena de 100 caracteres
            int inicio, fin;
            char* subcadena;

            limpiarBuffer(); // Limpiar el buffer antes de leer la cadena
            printf("Ingrese la cadena: ");
            fgets(cadena, sizeof(cadena), stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea al final

            if (cadena[0] == '\0') {
                printf("Error: La cadena no puede estar vacia.\n");
                break;
            }

            int longitud = strlen(cadena);
            printf("La cadena tiene %d caracteres.\n", longitud);

            do {
                printf("Ingrese el inicio del rango (entre 0 y %d): ", longitud - 1);
                char inicioStr[10];
                fgets(inicioStr, sizeof(inicioStr), stdin);
                inicio = atoi(inicioStr);
                if (inicio < 0 || inicio >= longitud) {
                    printf("Error: Ingrese un inicio dentro del rango valido.\n");
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Ingrese el fin del rango (entre %d y %d): ", inicio + 1, longitud);
                char finStr[10];
                fgets(finStr, sizeof(finStr), stdin);
                fin = atoi(finStr);
                if (fin <= inicio || fin > longitud) {
                    printf("Error: Ingrese un fin dentro del rango valido.\n");
                } else {
                    break;
                }
            } while (1);

            subcadena = obtenerSubcadena(cadena, inicio, fin);
            if (subcadena != NULL) {
                printf("La subcadena es: %s\n", subcadena);
                free(subcadena); // Liberar la memoria asignada a la subcadena
            } else {
                printf("Error: El rango especificado es invalido.\n");
            }

            break;
        }

        case 2: {
            char cadena1[100];
            char cadena2[100];
            char* diferencia;

            limpiarBuffer();
            printf("Ingrese la primera cadena: ");
            fgets(cadena1, sizeof(cadena1), stdin);
            cadena1[strcspn(cadena1, "\n")] = '\0'; // Eliminar el salto de línea al final

            if (cadena1[0] == '\0') {
                printf("Error: La primera cadena no puede estar vacia.\n");
                break;
            }

            limpiarBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(cadena2, sizeof(cadena2), stdin);
            cadena2[strcspn(cadena2, "\n")] = '\0'; // Eliminar el salto de línea al final

            if (cadena2[0] == '\0') {
                printf("Error: La segunda cadena no puede estar vacia.\n");
                break;
            }

            // Llamada a la función para obtener la diferencia entre cadenas
            diferencia = obtenerDiferencia(cadena1, cadena2);
            if (diferencia != NULL) {
                printf("La diferencia entre las cadenas es: %s\n", diferencia);
                free(diferencia);
            } else {
                // Buscar y mostrar caracteres repetidos
                printf("No se puede calcular la diferencia debido a caracteres repetidos en las cadenas: ");
                for (int i = 0; i < strlen(cadena1); i++) {
                    for (int j = 0; j < strlen(cadena2); j++) {
                        if (cadena1[i] == cadena2[j]) {
                            printf("%c ", cadena1[i]);
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
