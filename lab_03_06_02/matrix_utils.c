#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

void fill_matrix(matrix *matr)
{
    int value = 1;
    int direction = 0;

    for (int j = matr->col_count - 1; j >= 0; j--)
    {
        if (direction == 0)
        {
            for (int i = matr->row_count - 1; i >= 0; i--)
            {
                matr->data[i][j] = value;
                value++;
            }
        }
        else
        {
            for (int i = 0; i < matr->row_count; i++)
            {
                matr->data[i][j] = value;
                value++;
            }
        }

        direction = !direction;
    }
}
