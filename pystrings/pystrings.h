#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define False 0
#define True 1

typedef unsigned char bool;

bool _isnum(char c);

bool isnum(char * str);

char * capitalize(char * str);

char * center(char * str, int width, char fillchar);

int count(char * str, char * substr);

bool endswith(char * str, char * substr);

char ** split(char * str, char sep, int * arrlen);

void aprint(char ** arr, size_t size);

char * raw_input(size_t max_len, char * prompt);
