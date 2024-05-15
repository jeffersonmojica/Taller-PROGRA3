#include "function.h"

#include <ctype.h>
#include <string.h>



void removeDuplicates(char* str) {
    int j=0;
    for (int i=0; i<strlen(str);i++){
        int alreadyAppeared = 0;
        for (int k = 0; k < i; k++) {
            if (str[i] == str[k]) {
                alreadyAppeared = 1;
                break;
            }
        }
        if (!alreadyAppeared) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';

}

void orderStr(char* str) {

    for (int i = 0; i < strlen(str); i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (tolower(str[i]) > tolower(str[j])) {
                char aux = str[i];
                str[i] = str[j];
                str[j] = aux;
            }
        }
    }
}

void fillString(char *string, const char character, const int direction, const int numCharacters) {
    if (direction != 0 && direction != 1) {
        return;
    }

    const size_t len = strlen(string);

    if (direction == 0) {
        for (int i = 0; i < len; i++) {
            string[len - 1 - i + numCharacters] = string[len - 1 - i];
        }
    }

    const int beginning = direction == 0 ? 0 : len;
    for (int i = 0; i < numCharacters; i++) {
        string[beginning + i] = character;
    }

    string[len + numCharacters] = '\0';
}