#ifndef FUNCTION_H
#define FUNCTION_H
#include <stddef.h>

void removeDuplicates(char *str);

void orderStr(char *str);

void fillString(char *string, char character, int direction, int numCharacters);

inline void read_string(const char *msg, char *string, const size_t input_len);

#endif
