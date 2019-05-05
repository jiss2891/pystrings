#include <stdlib.h>
#include <stdio.h>
#include "pystrings/pystrings.h"

#define for(i, a, b) for (int i = a; i < b; i++)

int main(){
  int alen = 0;
  char ** array;
  char * input;

  input = raw_input(100, "Write something separated with comma: ");

  array = split(input, ',', &alen);

  aprint(array, alen);

  for (i, 0, alen)
    free(array[i]);

  free(array);
  free(input);

  return 0;
}
