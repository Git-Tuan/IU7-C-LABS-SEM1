#include <stdio.h>
#include "matrix_utils.h"

static int check_column(matrix *matr, int col)
{
    int sign_interchange = 1;
    for (int i = 0; i < matr->row_count - 1; i++)
    {
        if (matr->data[i][col] == 0 || matr->data[i + 1][col] == 0)
            sign_interchange = 0;

        if ((matr->data[i][col] > 0 && matr->data[i + 1][col] > 0) ||
            (matr->data[i][col] < 0 && matr->data[i + 1][col] < 0))
            sign_interchange = 0;
    }

    return sign_interchange;
}

void build_result(matrix *matr, int result[])
{
    for (int j = 0; j < matr->col_count; j++)
        result[j] = check_column(matr, j);
}
