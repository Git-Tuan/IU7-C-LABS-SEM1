#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "matrix_utils.h"
#include "status.h"

status_code read_size(int *rows, int *cols);
status_code read_matrix(matrix *mat);
void print_matrix(matrix *mat);

#endif
