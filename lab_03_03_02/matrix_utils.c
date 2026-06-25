#include <stdio.h>
#include "matrix_utils.h"
#include "status.h"

static long long row_product(int row[MAX], int cols)
{
    long long p = 1;

    for (int j = 0; j < cols; j++)
        p *= row[j];

    return p;
}

static void swap_rows(int a[MAX], int b[MAX], int cols)
{
    for (int i = 0; i < cols; i++)
    {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

void sort_rows_by_product(matrix *matr)
{
    long long prod[MAX];

    for (int i = 0; i < matr->row_count; i++)
        prod[i] = row_product(matr->data[i], matr->col_count);

    for (int i = 0; i < matr->row_count - 1; i++)
    {
        for (int j = 0; j < matr->row_count - i - 1; j++)
        {
            if (prod[j] > prod[j + 1])
            {
                long long tmp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = tmp;

                swap_rows(matr->data[j], matr->data[j + 1], matr->col_count);
            }
        }
    }
}

