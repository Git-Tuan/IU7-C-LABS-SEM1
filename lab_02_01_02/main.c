#include <math.h>
#include <stdio.h>

#define N 10

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERR = 1,
    STATUS_N_IS_NEGATIVE_ERR = 2,
    STATUS_NEGATIVE_NOT_FOUND_ERR = 3,
    STATUS_N_LIMIT_ERR = 4
} return_code_t;

return_code_t input_size(int *n);
return_code_t input_array(int *arr_pointer, int n);
return_code_t arithmetic_average(int *arr_pointer, int n, double *result);

int main(void)
{
    int n;
    int array[N];
    double result = 0.0;
    return_code_t status = STATUS_OK;

    status = input_size(&n);

    if (status == STATUS_OK)
        status = input_array(array, n);
    if (status == STATUS_OK)
        status = arithmetic_average(array, n, &result);
    if (status == STATUS_OK)
        printf("%lf\n", result);

    return status;
}

return_code_t input_size(int *n)
{
    return_code_t rc = STATUS_OK;

    printf("Enter N: ");
    if (scanf("%d", n) == 1)
    {
        if (*n <= 0)
            rc = STATUS_N_IS_NEGATIVE_ERR;
        else if (*n >= N)
            rc = STATUS_N_LIMIT_ERR;
    }
    else
        rc = STATUS_INPUT_ERR;

    return rc;
}

return_code_t input_array(int *arr_pointer, int n)
{
    return_code_t rc = STATUS_OK;

    printf("Enter array elements:\n");
    for (int i = 0; i < n && rc == STATUS_OK; i++)
    {
        if (scanf("%d", arr_pointer + i) != 1)
            rc = STATUS_INPUT_ERR;
    }
    return rc;
}

return_code_t arithmetic_average(int *arr_pointer, int n, double *result)
{
    return_code_t rc = STATUS_OK;
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr_pointer[i] < 0)
        {
            sum += arr_pointer[i];
            count++;
        }
    }
    if (count == 0)
        rc = STATUS_NEGATIVE_NOT_FOUND_ERR;
    else
        *result = sum / count;

    return rc;
}


