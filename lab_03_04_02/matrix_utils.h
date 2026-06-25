#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H
#define MAX 10

typedef struct
{
    int data[MAX][MAX];
    int *rows[MAX];
    int row_count;
    int col_count;
} matrix;

int find_max(matrix *matr, int *result);

#endif
