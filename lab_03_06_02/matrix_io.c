#include "matrix_io.h"
#include "status.h"
#include <stdio.h>

status_code read_size(int *rows, int *cols)
{
    status_code status = STATUS_OK;
    if (scanf("%d %d", rows, cols) != 2)
        status = STATUS_INPUT_ERROR;
    else if (*rows <= 0 || *rows > MAX || *cols <= 0 || *cols > MAX)
        status = STATUS_INVALID_SIZE_ERROR;

    return status;
}

void print_matrix(matrix *mat)
{
    for (int i = 0; i < mat->row_count; i++)
    {
        for (int j = 0; j < mat->col_count; j++)
            printf("%d ", mat->data[i][j]);
        printf("\n");
    }
}
