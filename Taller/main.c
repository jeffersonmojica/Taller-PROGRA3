#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void manejarOpcion(int opcion);

char* obtenerSubcadena(const char* cadena, int inicio, int fin) {
    if (cadena == NULL || inicio < 0 || fin < 0 || inicio > strlen(cadena) || fin > strlen(cadena)) {
        return NULL;
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

    subcadena[longitud] = '\0';
    return subcadena;
}

char* obtenerDiferencia(const char* cadena1, const char* cadena2) {
    if (cadena1 == NULL || cadena2 == NULL) {
        return NULL;
    }

    int caracteres[256] = {0};
    for (int i = 0; i < strlen(cadena2); i++) {
        caracteres[(int)cadena2[i]]++;
    }

    for (int i = 0; i < strlen(cadena1); i++) {
        if (caracteres[(int)cadena1[i]] > 0) {
            return NULL;
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
                free(subcadena);
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
            cadena1[strcspn(cadena1, "\n")] = '\0';

            if (cadena1[0] == '\0') {
                printf("Error: La primera cadena no puede estar vacia.\n");
                break;
            }

            limpiarBuffer();
            printf("Ingrese la segunda cadena: ");
            fgets(cadena2, sizeof(cadena2), stdin);
            cadena2[strcspn(cadena2, "\n")] = '\0';

            if (cadena2[0] == '\0') {
                printf("Error: La segunda cadena no puede estar vacia.\n");
                break;
            }

            diferencia = obtenerDiferencia(cadena1, cadena2);
            if (diferencia != NULL) {
                printf("La diferencia entre las cadenas es: %s\n", diferencia);
                free(diferencia);
            } else {
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
