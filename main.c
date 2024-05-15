

#include "Programa.h"
#include "ChangeString.h"
#include "Punto1_5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "function.h"

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
        printf("2. Funcion que rellena de caracteres a la izquierda o derecha de una cadena\n");
        printf("3. Funcion que retorna una subcadena\n");
        printf("4. Funcion que reemplaza todas las ocurrencias de un caracter por otro\n");
        printf("5. Validar si una cadena inicia con otra\n");
        printf("6. Funcion que retorna cadena sin caracteres repetidos\n");
        printf("7. Funcion que realiza una operacion de diferencia entre dos cadenas\n");
        printf("9. Funcion que ordena una cadena\n");
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
        fflush(stdin);
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
                printf("Numero total de ocurrencias encontradas: %d\n", searchSubstring(cadena, subcadena, posicionInicio));
                break;

            case 2: {
                const size_t input_size=100;
                char str[input_size];
                char input[10];
                char character;
                int aux;
                int ret,ret2;
                int flag;
                char *ptr;

                read_string("Ingrese la cadena a la cual agregar caracteres: ", str, input_size);
                do {
                    aux = 0;
                    printf("Ingresa un caracter: ");
                    character = getchar();

                    if(getchar() != '\n') {
                        printf("Error: se ingreso mas de un caracter.\n");
                        aux = 1;

                        while (getchar() != '\n');
                    }
                } while(aux);
                do {
                    aux=0;
                    printf("Ingrese (0) si quiere agregar caracteres a la izquierda o (1) para agregar a la derecha");
                    fgets(input, sizeof(input), stdin);

                    ret = strtol(input, &ptr, 10);

                    if (ptr == input) {
                        printf("El valor ingresado no es un numero.\n");
                        flag = 1;
                    } else if (ret != 1 && ret != 0) {
                        printf("El valor ingresado es un numero, pero no es ni 1 ni 0.\n");
                        flag = 1;
                    }
                }while(flag);
                do {
                    aux=0;
                    printf("Ingrese el numero de caracteres a rellenar");
                    fgets(input, sizeof(input), stdin);

                    ret2 = strtol(input, &ptr, 10);
                    if (ptr == input) {
                        printf("El valor ingresado no es un numero.\n");
                        flag = 1;
                    }
                }while(flag);
                fillString(str,character,ret, ret2);
                printf("La cadena mas los caracteres es: %s\n", str);
                break;
            }
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

            case 6:{
                const size_t input_size = 100;
                char str[input_size];
                read_string("Ingrese la cadena para remover duplicados: ", str, input_size);
                removeDuplicates(str);
                printf("Cadena sin duplicados: %s\n", str);
                break;
            }


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

            case 9:{
                const size_t input_size = 100;
                char str[input_size];
                read_string("Ingrese la cadena para ordenarla: ", str, input_size);
                orderStr(str);
                printf("La cadena ordenada es: %s\n", str);
                break;
            }

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
