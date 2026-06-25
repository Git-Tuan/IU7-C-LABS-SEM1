#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_N_NOT_POSITIVE_ERROR = 2,
    STATUS_NO_NUMBERS_FOUND_ERROR = 3,
    STATUS_N_LIMIT_ERROR = 4
} return_code_t;

return_code_t input_size(int *n);
return_code_t input_array(int *arr, int n);
void filter_numbers(int *src, int *dst, int *counter, int n);
void print_array(int *arr, int size);

int main(void)
{
    int n;
    int array[N];
    int new_array[N] = 
    {
        0
    };
    int counter = 0;
    return_code_t status = STATUS_OK;

    status = input_size(&n);

    if (status == STATUS_OK)
        status = input_array(array, n);
    if (status == STATUS_OK)
    {
        filter_numbers(array, new_array, &counter, n);
        if (counter == 0)
            status = STATUS_NO_NUMBERS_FOUND_ERROR;
    }
    if (status == STATUS_OK)
        print_array(new_array, counter);

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
        else if (*n > N)
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

void filter_numbers(int *src, int *dst, int *counter, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = src[i];
        int abs_num = abs(num);

        int last = abs_num % 10;
        int first = abs_num;
        while (first >= 10)
            first /= 10;

        if (first == last)
        {
            dst[*counter] = num;
            (*counter)++;
        }
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}


