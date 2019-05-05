#!/bin/bash

# JUST COMPILE DEMO AND RUN.
gcc -g -Wall -Werror -o main demo.c pystrings/pystrings.c && valgrind --leak-check=full -v ./main
