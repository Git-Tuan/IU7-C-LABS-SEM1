#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "status.h"
#include "matrix_utils.h"
#define MAX 10

status_code read_size(int *rows, int *cols);
void transform_matrix(int (*data)[MAX], int **matr, int rows);
status_code read_matrix(matrix *mat);

#endif
