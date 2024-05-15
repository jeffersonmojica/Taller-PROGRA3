//
// Created by JeffersonMT on 14/05/2024.
//
#include "Programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* getSubstring(const char* string, int start, int end) {
    if (string == NULL || start < 0 || end < 0 || start > strlen(string) || end > strlen(string)) {
        return NULL;
    }

    char* substring;
    int length;

    if (end == 0) {
        length = strlen(string) - start;
        substring = (char*)malloc((length + 1) * sizeof(char));
        strncpy(substring, string + start, length);
    } else if (start > end) {
        length = start - end + 1;
        substring = (char*)malloc((length + 1) * sizeof(char));
        for (int i = start, j = 0; i >= end; i--, j++) {
            substring[j] = string[i];
        }
        substring[length] = '\0';
    } else {
        length = end - start + 1;
        substring = (char*)malloc((length + 1) * sizeof(char));
        strncpy(substring, string + start, length);
    }

    substring[length] = '\0';
    return substring;
}

char* getDifference(const char* string1, const char* string2) {
    if (string1 == NULL || string2 == NULL) {
        return NULL;
    }

    int characters[256] = {0};
    for (int i = 0; i < strlen(string2); i++) {
        characters[(int)string2[i]]++;
    }

    for (int i = 0; i < strlen(string1); i++) {
        if (characters[(int)string1[i]] > 0) {
            return NULL;
        }
    }

    // Calculate the difference between strings
    char* difference = (char*)malloc((strlen(string1) + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (!strchr(string2, string1[i])) {
            difference[j++] = string1[i];
        }
    }
    difference[j] = '\0';

    return difference;
}
