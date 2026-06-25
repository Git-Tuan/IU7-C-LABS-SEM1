#include <stdio.h>

#define N 10

typedef enum
{
    SUCCESS,
    FAIL,
    SPECIAL_CODE = 100
} return_code_t;

int initialize_array(int *arr_pointer, int *st);
void insertion_sort(int *arr, int size);
void print_array(int counter, int *new_arr);

int main(void)
{
    int array[N] = 
    {
        0
    };
    int size = 0;
    int status = SUCCESS;

    size = initialize_array(array, &status);
    if (size > 0)
    {
        insertion_sort(array, size);
        print_array(size, array);
    }
    else
    {
        printf("Error: No numbers found");
        status = FAIL;
    }

    return status;
}

int initialize_array(int *arr_pointer, int *st)
{
    int i = 0;
    int status = 1;

    printf("Enter array elements (enter non-number to stop):\n");

    for (; i < N && status == 1;)
    {
        status = scanf("%d", (arr_pointer + i));
        if (status == 1)
            i++;
    }

    if (i == N)
    {
        int x;
        if (scanf("%d", &x) == 1)
            *st = SPECIAL_CODE;
    }

    return i;
}

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        for (; j >= 0 && key < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}

void print_array(int size, int *new_arr)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", new_arr[i]);
    }
}

