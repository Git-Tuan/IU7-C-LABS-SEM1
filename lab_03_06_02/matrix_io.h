#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "matrix_utils.h"
#include "status.h"
#define MAX 10

void print_matrix(matrix *mat);
status_code read_size(int *rows, int *cols);

#endif
