#include <stdlib.h>
#include <stdio.h>
#include "pystrings/pystrings.h"

#define for(i, a, b) for (int i = a; i < b; i++)

int main(){
  int alen = 0;
  char * input;
  char ** array;
  input = raw_input(100, "Ingresa una frase: ");
  array = split(input, ',', &alen);
  printf("%s", aprint(array, alen));

  for (i, 0, alen)
    printf("%s", array[i]);

  free(array);

  return 0;
}
