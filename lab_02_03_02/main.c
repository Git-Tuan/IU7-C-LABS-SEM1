#include <math.h>
#include <stdio.h>

#define N 10

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_N_NOT_POSITIVE_ERROR = 2,
    STATUS_N_LIMIT_ERROR = 3,
    STATUS_EMPTY_ARRAY_ERROR = 4
} return_code_t;

return_code_t input_size(int *n);
return_code_t input_array(int *arr, int n);
void remove_full_square(int *arr, int *size);
void print_array(int *arr, int size);

int main(void)
{
    int n;
    int array[N];

    return_code_t status = STATUS_OK;

    status = input_size(&n);

    if (status == STATUS_OK)
        status = input_array(array, n);
    if (status == STATUS_OK)
    {
        remove_full_square(array, &n);
        if (n == 0)
            status = STATUS_EMPTY_ARRAY_ERROR;
    }
    if (status == STATUS_OK)
        print_array(array, n);

    return status;
}

return_code_t input_size(int *n)
{
    return_code_t rc = STATUS_OK;

    printf("Enter N: ");
    if (scanf("%d", n) == 1)
    {
        if (*n <= 0)
            rc = STATUS_N_NOT_POSITIVE_ERROR;
        else if (*n >= N)
            rc = STATUS_N_LIMIT_ERROR;
    }
    else
        rc = STATUS_INPUT_ERROR;

    return rc;
}

return_code_t input_array(int *arr_pointer, int n)
{
    return_code_t rc = STATUS_OK;

    printf("Enter array elements:\n");
    for (int i = 0; i < n && rc == STATUS_OK; i++)
    {
        if (scanf("%d", arr_pointer + i) != 1)
            rc = STATUS_INPUT_ERROR;
    }
    return rc;
}

void remove_full_square(int *arr, int *size)
{
    int write = 0;

    for (int read = 0; read < *size; read++)
    {
        int root = (int)sqrt(arr[read]);

        if (arr[read] != root * root)
        {
            arr[write] = arr[read];
            write++;
        }
    }

    *size = write;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}



