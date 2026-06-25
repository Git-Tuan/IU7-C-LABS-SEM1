#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

static int digit_sum(int x)
{
    if (x < 0)
        x = -x;

    int sum = 0;

    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

static status_code has_two_odd_digit_sum(int *row, int cols)
{
    int count = 0;
    status_code status = STATUS_OK;

    for (int j = 0; j < cols && status == STATUS_OK; j++)
    {
        if (digit_sum(row[j]) % 2 == 1)
        {
            count++;

            if (count >= 2)
                status = STATUS_INPUT_ERROR;
        }
    }

    return status;
}

status_code insert_rows(matrix *mat, int *new_rows)
{
    status_code rc = STATUS_OK;
    int i = 0;
    int rows = mat->row_count;
    int cols = mat->col_count;

    while (i < rows && rc == STATUS_OK)
    {
        if (has_two_odd_digit_sum(mat->rows[i], cols))
        {
            if (rows >= MAX)
            {
                printf("Недостаточно места для вставки строк\n");
                rc = STATUS_INSERT_NO_SPACE_ERROR;
            }
            else
            {
                for (int k = rows; k > i; k--)
                    for (int j = 0; j < cols; j++)
                        mat->rows[k][j] = mat->rows[k - 1][j];

                for (int j = 0; j < cols; j++)
                    mat->rows[i][j] = -1;

                rows++;
                i += 2;
                mat->row_count = rows;
            }
        }
        else
        {
            i++;
        }
    }

    *new_rows = rows;

    return rc;
}
