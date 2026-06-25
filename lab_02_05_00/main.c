#include <stdio.h>

#define N 10

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_N_NOT_POSITIVE_ERROR = 2,
    STATUS_N_LIMIT_ERROR = 3,
    STATUS_N_EQUALS_ONE = 4
} return_code_t;

return_code_t input_size(int *n);
return_code_t input_array(int *arr, int n);
int find_max_sum(int *start, int *end);

int main(void)
{
    int n;
    return_code_t status = STATUS_OK;
    int max_sum = 0;
    int array[N];

    status = input_size(&n);

    if (status == STATUS_OK)
        status = input_array(array, n);
    if (status == STATUS_OK)
    {
        max_sum = find_max_sum(array, array + n);
        printf("%d", max_sum);
    }

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
        else if (*n == 1)
            rc = STATUS_N_EQUALS_ONE;
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

int find_max_sum(int *start, int *end)
{
    int *left = start;
    int *right = end - 1;

    int max = *left + *right;

    for (; left <= right; left++, right--)
    {
        int sum = *left + *right;

        if (sum > max)
            max = sum;
    }

    return max;
}


