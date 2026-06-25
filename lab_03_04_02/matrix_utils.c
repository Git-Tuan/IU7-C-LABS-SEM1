#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

int find_max(matrix *matr, int *result)
{
    int found = 0;
    int n = matr->row_count;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matr->col_count; j++)
        {
            if (i + j > n - 1 && abs(matr->data[i][j]) % 10 == 5)
            {
                if (!found || matr->data[i][j] > *result)
                {
                    *result = matr->data[i][j];
                    found = 1;
                }
            }
        }
    }

    return found;
}
