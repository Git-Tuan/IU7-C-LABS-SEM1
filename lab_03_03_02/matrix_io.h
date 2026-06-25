#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "status.h"
#include "matrix_utils.h"
#define MAX 10

status_code read_matrix(matrix *mat);
void print_matrix(matrix *mat);
status_code read_size(int *rows, int *cols);

#endif
