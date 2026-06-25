#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "status.h"
#include <stdio.h>

int process(FILE *f, int *max_digit, int *second_max_digit);
void print_result(int max_digit, int second_max_digit);

#endif
