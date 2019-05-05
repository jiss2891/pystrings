#include <stdlib.h>
#include <stdio.h>
#include "pystrings/pystrings.h"

#define for(i, a, b) for (int i = a; i < b; i++)

int main(){
  int alen = 0;
  char ** array;
  char * input;
  char * representation;

  input = raw_input(100, "Write something separated with comma: ");

  array = split(input, ',', &alen);

  representation = aprint(array, alen);

  printf("%s\n", representation);

  for (i, 0, alen)
    free(array[i]);

  free(array);
  free(input);
  free(representation);

  return 0;
}
