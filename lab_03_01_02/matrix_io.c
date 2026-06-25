#include <stdio.h>
#include "matrix_io.h"

status_code read_size(int *rows, int *cols)
{
    status_code status = STATUS_OK;
    if (scanf("%d %d", rows, cols) != 2)
        status = STATUS_INPUT_ERROR;
    else if (*rows <= 0 || *rows > MAX || *cols <= 0 || *cols > MAX)
        status = STATUS_SIZE_ERROR;

    return status;
}

status_code read_matrix(matrix *mat)
{
    status_code status = STATUS_OK;

    for (int i = 0; i < mat->row_count && status == STATUS_OK; i++)
    {
        mat->rows[i] = mat->data[i];

        for (int j = 0; j < mat->col_count && status == STATUS_OK; j++)
        {
            if (scanf("%d", &mat->data[i][j]) != 1)
                status = STATUS_INPUT_ERROR;
        }
    }

    return status;
}

