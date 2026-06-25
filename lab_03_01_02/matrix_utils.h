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

void build_result(matrix *matr, int result[]);

#endif
