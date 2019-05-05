#include <stdlib.h>
#include <stdio.h>
#include "pystrings/pystrings.h"

#define for(i, a, b) for (int i = a; i < b; i++)

int main(){
  int alen = 0;
  char ** array;
  char * input;

  // I choose 3100 in order to support the provided input files.
  input = raw_input(3100, "Write something separated with comma: ");

  array = split(input, '$', &alen);

  aprint(array, alen);

  for (i, 0, alen)
    printf("%s\n", center(array[i], 100, ' '));
  for (i, 0, alen)
    free(array[i]);

  free(array);
  free(input);

  return 0;
}
