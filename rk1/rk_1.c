#include <stdio.h>

#define N 10

void buffer_print(int *arr, int front_pos, int size);
void buffer_push_back(int *arr, int value, int *back_pos, int *size);
void buffer_push_front(int *arr, int value, int *front_pos, int *size);
int buffer_pop_back(int *arr, int *back_pos, int *size);
int buffer_pop_front(int *arr, int *front_pos, int *size);
int buffer_remove(int *arr, int *front_pos, int *back_pos, int *size, int index);

void buffer_push_back(int *arr, int value, int *back_pos, int *size)
{
    if (*size != N)
    {
        arr[*back_pos] = value;
        *back_pos = (*back_pos + 1) % N;
        (*size)++;
    }
}

void buffer_push_front(int *arr, int value, int *front_pos, int *size)
{
    if (*size != N)
    {
        *front_pos = (*front_pos - 1 + N) % N;
        arr[*front_pos] = value;
        (*size)++;
    }
}

int buffer_pop_back(int *arr, int *back_pos, int *size)
{
    int value = -1;
    if (*size != 0)
    {
        *back_pos = (*back_pos - 1 + N) % N;
        value = arr[*back_pos];
        (*size)--;
    }
    return value;
}

int buffer_pop_front(int *arr, int *front_pos, int *size)
{
    int value = -1;
    if (*size != 0)
    {
        value = arr[*front_pos];
        *front_pos = (*front_pos + 1) % N;
        (*size)--;
    }
    return value;
}

int buffer_remove(int *arr, int *front_pos, int *back_pos, int *size, int index)
{
    int value = -1;
    if (index >= 0 && index < *size)
    {
        int pos = (*front_pos + index) % N;
        value = arr[pos];
        for (int i = index; i < *size - 1; i++)
        {
            int cur = (*front_pos + i) % N;
            int next = (*front_pos + i + 1) % N;
            arr[cur] = arr[next];
        }
        *back_pos = (*back_pos - 1 + N) % N;
        (*size)--;
    }
    return value;
}

void buffer_print(int *arr, int front_pos, int size)
{
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[(front_pos + i) % N]);
        }
        printf("\n");
    }
}

int main(void)
{
    int arr[N];
    int front_pos = 0, back_pos = 0, size = 0;

    while (1)
    {
        printf("Enter value for push back: ");
        int value;
        scanf("%d", &value);
        if (value >= 0)
            buffer_push_back(arr, value, &back_pos, &size);
        else
            break;
    }

    buffer_push_front(arr, 67, &front_pos, &size);
    buffer_push_back(arr, 666, &back_pos, &size);
    buffer_print(arr, front_pos, size);

    buffer_pop_front(arr, &front_pos, &size);
    buffer_pop_back(arr, &back_pos, &size);

    buffer_print(arr, front_pos, size);

    buffer_remove(arr, &front_pos, &back_pos, &size, 1);
    buffer_print(arr, front_pos, size);

    return 0;
}