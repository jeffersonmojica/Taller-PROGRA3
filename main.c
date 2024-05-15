/*#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Punto1_5.h"
#include "ChangeString.h"
#include "Programa.h"

int main() {
    char cadena[101]; // Tamaño para la cadena base
    char subcadena[50]; // Tamaño para la subcadena
    int opcion, posicionInicio;
    int inicio;
    char c;
    char optionStr[10];
    int option;
    char string[100];
    int start, end;
    char* substring;
    char string1[100];
    char string2[100];
    char* difference;


    do {
        printf("\nMenu de opciones:\n");

        printf("1. Buscar todas las ocurrencias de una subcadena\n");

        printf("3. Función  que  retorna  una  subcadena,  \n");

        printf("4.Función que reemplaza todas las ocurrencias de un carácter por otro \n");

        printf("5. Validar si una cadena inicia con otra\n");

        printf("7.Función que realiza una operación de diferencia entre dos cadenas,  \n");

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



        switch (opcion) {
            case 1:
                printf("Ingrese la cadena base: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese la subcadena a buscar: ");
                scanf("%s", subcadena);
                while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
                printf("Introduzca la posición desde donde iniciar la búsqueda: ");
                scanf("%d", &posicionInicio);
                while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
                printf("Número total de ocurrencias encontradas: %d\n", searchSubstring(cadena, subcadena, posicionInicio));
                break;

            case 3:
                printf("Ingrese la cadena: ");
                fgets(string, sizeof(string), stdin);
                string[strcspn(string, "\n")] = '\0';

                if (string[0] == '\0') {
                    printf("Error: La cadena no puede estar vacia.\n");
                    break;
                }

                int length = strlen(string);
                printf("La cadena tiene %d caracteres.\n", length);

                do {
                    printf("Ingrese el inicio del rango (entre 0 y %d): ", length - 1);
                    char startStr[10];
                    fgets(startStr, sizeof(startStr), stdin);
                    start = atoi(startStr);
                    if (start < 0 || start >= length) {
                        printf("Error: Ingrese un inicio dentro del rango valido.\n");
                    } else {
                        break;
                    }
                } while (1);

                do {
                    printf("Ingrese el fin del rango (entre %d y %d): ", start + 1, length);
                    char endStr[10];
                    fgets(endStr, sizeof(endStr), stdin);
                    end = atoi(endStr);
                    if (end <= start || end > length) {
                        printf("Error: Ingrese un fin dentro del rango valido.\n");
                    } else {
                        break;
                    }
                } while (1);

                substring = (char *) getSubstring(string, start, end);
                if (substring != NULL) {
                    printf("La subcadena es: %s\n", substring);
                    free(substring);
                } else {
                    printf("Error: El rango especificado es invalido.\n");
                }

                break;








            case 4:
                ReplaceCharacters();
                break;



















            case 5:
                printf("Ingrese la cadena base: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese la cadena a verificar si inicia con: ");
                fgets(subcadena, sizeof(subcadena), stdin);
                subcadena[strcspn(subcadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                inicio = stringStartWith(cadena, subcadena);
                printf("%d\n", inicio);
                break;




            case 7:

                clearBuffer();
                printf("Ingrese la primera cadena: ");
                fgets(string1, sizeof(string1), stdin);
                string1[strcspn(string1, "\n")] = '\0';

                if (string1[0] == '\0') {
                    printf("Error: La primera cadena no puede estar vacia.\n");
                    break;
                }

                clearBuffer();
                printf("Ingrese la segunda cadena: ");
                fgets(string2, sizeof(string2), stdin);
                string2[strcspn(string2, "\n")] = '\0';

                if (string2[0] == '\0') {
                    printf("Error: La segunda cadena no puede estar vacia.\n");
                    break;
                }

                difference = getDifference(string1, string2);
                if (difference != NULL) {
                    printf("La diferencia entre las cadenas es: %s\n", difference);
                    free(difference);
                } else {
                    printf("No se puede calcular la diferencia debido a caracteres repetidos en las cadenas: ");
                    for (int i = 0; i < strlen(string1); i++) {
                        for (int j = 0; j < strlen(string2); j++) {
                            if (string1[i] == string2[j]) {
                                printf("%c ", string1[i]);
                            }
                        }
                    }
                    printf("\n");
                }

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

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}*/


#include "Programa.h"
#include "ChangeString.h"
#include "Punto1_5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char cadena[101]; // Tamaño para la cadena base
    char subcadena[50]; // Tamaño para la subcadena
    int opcion, posicionInicio;
    int inicio;
    char c;
    char string[100];
    int start, end;
    char* substring;
    char string1[100];
    char string2[100];
    char* difference;

    do {
        printf("\nMenu de opciones:\n");

        printf("1. Buscar todas las ocurrencias de una subcadena\n");
        printf("3. Funcion que retorna una subcadena\n");
        printf("4. Funcion que reemplaza todas las ocurrencias de un caracter por otro\n");
        printf("5. Validar si una cadena inicia con otra\n");
        printf("7. Funcion que realiza una operacion de diferencia entre dos cadenas\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Se debe ingresar un numero.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (opcion < 1 || opcion > 9) {
            printf("Error: Opcion fuera de rango.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese la cadena base: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese la subcadena a buscar: ");
                scanf("%s", subcadena);
                clearBuffer();
                printf("Introduzca la posicion desde donde iniciar la busqueda: ");
                scanf("%d", &posicionInicio);
                clearBuffer();
                printf("Número total de ocurrencias encontradas: %d\n", searchSubstring(cadena, subcadena, posicionInicio));
                break;

            case 3:
                printf("Ingrese la cadena: ");
                fgets(string, sizeof(string), stdin);
                string[strcspn(string, "\n")] = '\0';

                if (string[0] == '\0') {
                    printf("Error: La cadena no puede estar vacia.\n");
                    break;
                }

                int length = strlen(string);
                printf("La cadena tiene %d caracteres.\n", length);

                do {
                    printf("Ingrese el inicio del rango (entre 0 y %d): ", length - 1);
                    char startStr[10];
                    fgets(startStr, sizeof(startStr), stdin);
                    start = atoi(startStr);
                    if (start < 0 || start >= length) {
                        printf("Error: Ingrese un inicio dentro del rango valido.\n");
                    } else {
                        break;
                    }
                } while (1);

                do {
                    printf("Ingrese el fin del rango (entre %d y %d): ", start + 1, length);
                    char endStr[10];
                    fgets(endStr, sizeof(endStr), stdin);
                    end = atoi(endStr);
                    if (end <= start || end > length) {
                        printf("Error: Ingrese un fin dentro del rango valido.\n");
                    } else {
                        break;
                    }
                } while (1);

                substring = (char *) getSubstring(string, start, end);
                if (substring != NULL) {
                    printf("La subcadena es: %s\n", substring);
                    free(substring);
                } else {
                    printf("Error: El rango especificado es invalido.\n");
                }

                break;

            case 4:
                ReplaceCharacters();
                break;

            case 5:
                printf("Ingrese la cadena base: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese la cadena a verificar si inicia con: ");
                fgets(subcadena, sizeof(subcadena), stdin);
                subcadena[strcspn(subcadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                inicio = stringStartWith(cadena, subcadena);
                printf("%d\n", inicio);
                break;

            case 7:
                clearBuffer();
                printf("Ingrese la primera cadena: ");
                fgets(string1, sizeof(string1), stdin);
                string1[strcspn(string1, "\n")] = '\0';

                if (string1[0] == '\0') {
                    printf("Error: La primera cadena no puede estar vacia.\n");
                    break;
                }

                clearBuffer();
                printf("Ingrese la segunda cadena: ");
                fgets(string2, sizeof(string2), stdin);
                string2[strcspn(string2, "\n")] = '\0';

                if (string2[0] == '\0') {
                    printf("Error: La segunda cadena no puede estar vacia.\n");
                    break;
                }

                difference = getDifference(string1, string2);
                if (difference != NULL) {
                    printf("La diferencia entre las cadenas es: %s\n", difference);
                    free(difference);
                } else {
                    printf("No se puede calcular la diferencia debido a caracteres repetidos en las cadenas: ");
                    for (int i = 0; i < strlen(string1); i++) {
                        for (int j = 0; j < strlen(string2); j++) {
                            if (string1[i] == string2[j]) {
                                printf("%c ", string1[i]);
                            }
                        }
                    }
                    printf("\n");
                }

                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
