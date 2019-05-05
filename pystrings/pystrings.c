#include "pystrings.h"

char * _clone(char * str){
  char * out = calloc(sizeof(char), strlen(str));
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
  int size = to - from + 1;
  char * out = malloc(sizeof(char) * size);
  for (int i = 0; i < size; i++){
    out[i] = str[from];
    from++;
  }
  return out;
}

char ** split(char * str, char sep, int * arrlen){ 
  *arrlen = ccount(str, sep) + 1;
  char ** array = malloc(sizeof(char*) * *arrlen);
  size_t str_len = strlen(str);
  int arrpos = 0;
  int last = 0;
  int upto = 0;

  for (int i = 0; i < str_len; i++){
    if (str[i] == sep){
      upto = i-1;
      if (last == upto)
        array[arrpos] = "";
      else
        array[arrpos] = slice(str, last, upto);
      arrpos++;
      i++;
      last = i;
    } else if (i + 1 == str_len) {
      upto = i;
      if (last == upto)
        array[arrpos] = "";
      else
        array[arrpos] = slice(str, last, upto);
      arrpos++;
      i++;
      last = i;
    }
  };
  return array;
}

char * aprint(char ** arr, size_t size){
  int count = 0;
  char * out;

  for (int i = 0; i < size; i++)
    count += strlen(arr[i]);

  out = calloc(sizeof(char), (count + 2*size));

  out = strcat(out, "[");
  for (int i = 0; i < size; i++)
    if (i + 1 == size){
      out = strcat(out, "'");
      out = strcat(out, arr[i]);
      out = strcat(out, "'");
    } else {
      out = strcat(out, "'");
      out = strcat(out, arr[i]);
      out = strcat(out, "', ");
    };
  out = strcat(out, "]");
  return out;
}

char * raw_input(size_t max_len, char * prompt){
  char * out = malloc(sizeof(char) * max_len);
  printf("%s", prompt);
  fgets(out, max_len, stdin);
  if ((strlen(out) > 0) && (out[strlen(out) - 1] == '\n'))
      out[strlen(out) - 1] = '\0';
  return out;
}
