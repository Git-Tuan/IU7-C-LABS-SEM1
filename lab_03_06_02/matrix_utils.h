#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H
#define MAX 10

typedef struct
{
    int data[MAX][MAX];
    int row_count;
    int col_count;
} matrix;

void fill_matrix(matrix *matr);

#endif
