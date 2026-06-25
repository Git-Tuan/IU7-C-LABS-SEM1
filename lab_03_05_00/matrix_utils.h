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

int collect_primes(matrix *matr, int arr[]);
void reverse_array(int arr[], int n);
void put_back(matrix *matr, int arr[]);

#endif
