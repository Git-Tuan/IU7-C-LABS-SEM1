#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include "status.h"

#define MAX 10

typedef struct
{
    int data[MAX][MAX];
    int *rows[MAX];
    int row_count;
    int col_count;
} matrix;

status_code insert_rows(matrix *mat, int *new_rows);

#endif
