#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

static int is_prime(int n)
{
    int rc = 1;

    if (n < 2)
        rc = 0;

    for (int i = 2; i * i <= n && rc; i++)
        if (n % i == 0)
            rc = 0;

    return rc;
}

int collect_primes(matrix *matr, int arr[])
{
    int k = 0;

    for (int i = 0; i < matr->row_count; i++)
        for (int j = 0; j < matr->col_count; j++)
            if (is_prime(matr->data[i][j]))
            {
                arr[k] = matr->data[i][j];
                k++;
            }

    return k;
}

void reverse_array(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}

void put_back(matrix *matr, int arr[])
{
    int k = 0;

    for (int i = 0; i < matr->row_count; i++)
        for (int j = 0; j < matr->col_count; j++)
            if (is_prime(matr->data[i][j]))
            {
                matr->data[i][j] = arr[k];
                k++;
            }
}
