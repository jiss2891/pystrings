#include "pystrings.h"

char * _clone(char * str){
  char * out = malloc(sizeof(char) * strlen(str) + 1);  // + 1 to allow strcpy to NULL terminate the string.
  strcpy(out, str);
  return out;
}

bool in_range(int value, int min, int max){
  return value >= min && value <= max;
}

bool all(char * str, bool (*f)(char)){
  // Receives a string and validates f against every char.
  bool truth = True;
  char * mov = str;

  while (truth && *mov)
    truth = truth && f(*mov++);

  free(mov);

  return truth;

}

bool _isnum(char c){
  return in_range(c, 48, 57);
}

bool _iscapital(char c){
  return in_range(c, 65, 90);
}

bool _issmall(char c){
  return in_range(c, 97, 122);
}

// PUBLIC FUNCTIONS

bool isnum(char * str){
  return all(str, _isnum);
}

char * capitalize(char * str){
  char * capitalized = _clone(str); 

  if (isalpha(str[0]) && !_iscapital(str[0]))
    capitalized[0] = capitalized[0] - 32;
  return capitalized;
}

char * center(char * str, int width, char fillchar){
  int len;
  int pivot = 0; 
  char * centered;

  if (str) len = strlen(str); else len = 0;

  if (width <= len){
    return str;
  } else {
    centered = malloc(sizeof(char) * width);
    pivot = (width - len) / 2;
    for (int i = 0; i < width; i++){
      if (i < pivot)
        centered[i] = fillchar;
      else if (i >= pivot + len)
        centered[i] = fillchar;
      else
        centered[i] = str[i - pivot];
    }
    return centered;
  } 
}

int ccount(char * str, char c){
  int counted = 0;
  for (int i = 0; i < strlen(str); i++)
    if (str[i] == c)
      counted++;
  return counted;
}

int count(char * str, char * substr){
  int counted = 0;
  int idx_to_check = 0;
  int idx_max = strlen(substr) - 1;

  for (int i = 0; i < strlen(str); i++){
    if (str[i] == substr[idx_to_check]){
      if (idx_to_check == idx_max){
        counted++;
        idx_to_check = 0;
      } else {
        idx_to_check++;
      }
    } else {
      idx_to_check = 0;
    }
  };

  return counted;
}

bool endswith(char * str, char * substr){
  int offset = strlen(str) -  strlen(substr);

  for (int i = 0; i < strlen(substr); i++)
    if (str[i + offset] != substr[i])
      return False;

  return True;
}

char * slice(char * str, int from, int to){
  /* Returns a slice of str from char `from` to char `to`*/
  int size;
  char * out; 
 
  if (to <= from){
    out = malloc(1);
    out = '\0';
    return out;
  } else {
    size  = to - from + 1;
    out = malloc(sizeof(char) * size + 1);
    out[size] = '\0';
    
    for (int i = 0; i < size; i++){
      out[i] = str[from];
      from++;
    }
    return out;
  }
}

char ** split(char * str, char sep, int * arrlen){ 
  *arrlen = ccount(str, sep) + 1;
  char ** array = malloc(sizeof(char*) * *arrlen);
  size_t str_len = strlen(str);
  int arrpos = 0;
  int prev = 0;
  int i = 0;
  int s = 0;

  for (s = 0; s < *arrlen; s++){
    for (; str[i] != sep && i <= str_len; i++);
    array[arrpos] = slice(str, prev, i - 1); 
    arrpos++;
    i++;
    prev = i;
  }

  return array;
}

void aprint(char ** arr, size_t size){
  printf("[");
  for (int i = 0; i < size; i++)
    if (i + 1 == size)
      printf("'%s'", arr[i]);
    else
      printf("'%s', ", arr[i]);
  printf("]\n");
}

char * raw_input(size_t max_len, char * prompt){
  char * out = malloc(sizeof(char) * max_len);
  printf("%s", prompt);
  fgets(out, max_len, stdin);
  if ((strlen(out) > 0) && (out[strlen(out) - 1] == '\n'))
      out[strlen(out) - 1] = '\0';
  return out;
}
