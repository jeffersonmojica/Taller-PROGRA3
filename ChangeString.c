//
// Created by angel on 14/05/2024.
//

#include "ChangeString.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ReplaceCharacters() {
    printf("Bienvenido\n");
    printf("Digite la cadena que va a modificar: ");

    char Text [100];
    scanf("%s", Text);

    char a, b;
    printf("Digite el caracter a ser reemplazado: ");
    scanf(" %c", &a);

    printf("Digite el nuevo caracter: ");
    scanf(" %c", &b);


    if (!isalpha(a) || !isalpha(b)) {
        printf("Error: Los caracteres deben ser letras.\n");
        return 1;
    }

    for (int i = 0; Text[i] != '\0'; ++i) {
        if (Text[i] == a) {
            Text[i] = b;
        }
    }

    printf("La nueva cadena es %s\n", Text );

    return 0;
}
void InsertSubstring(char *original, const char *subcadena, int indice) {
    int lengthOriginal = strlen(original);
    int lengthsubtext = strlen(subcadena);


    if (indice < 0 || indice > lengthOriginal) {
        printf("Error: La posición de inserción está fuera de los límites.\n");
        return;
    }


    for (int i = lengthOriginal; i >= indice; --i) {
        original[i + lengthsubtext] = original[i];
    }


    for (int i = 0; i < lengthsubtext; ++i) {
        original[indice + i] = subcadena[i];
    }
}
