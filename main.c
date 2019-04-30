#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pystrings/pystrings.h"


int main(){
  printf("isnum: %d", isnum("31012938012983"));
  printf("isnum: %d", isnum("1129387122za"));
  printf("capitalize: %s\n", capitalize("hola"));
  printf("capitalize: %s\n", capitalize("Hhola"));
  printf("capitalize: %s\n", capitalize("123hola"));
  printf("capitalize: %s\n", capitalize("#123hola"));
  printf("center: %s\n", center("AB", 3, '#'));
  printf("center: %s\n", center("AB", 4, '#'));
  printf("center: %s\n", center("ABC", 4, '#'));
  printf("center: %s\n", center("ABC", 20, '#'));
  printf("count: %d\n", count("holaholahola", "hola"));
  printf("count: %d\n", count("chauchauchau", "hola"));
  printf("count: %d\n", count("chauholahole", "hola"));
  printf("endswith %d\n", endswith("chauholahole", "hole"));
  printf("endswith %d\n", endswith("False", "alse"));
  printf("endswith %d\n", endswith("False    3", "alse"));
  printf("endswith %d\n", endswith("True", "ru"));
  printf("endswith %d\n", endswith("True", "rue"));
  int arraysize;
  char * input = raw_input(30, "Ingrese valores separados por coma: ");
  char ** array = split(input, ',', &arraysize);

  for (int i = 0; i < arraysize; i++)
    printf("%s\n", center(array[i], 20, '~'));

  return 0;
}
