#include "file_utils.h"
#include <stdio.h>

void print_result(int max_digit, int second_max_digit)
{
    printf("%d\n%d\n", max_digit, second_max_digit);
}

int process(FILE *f, int *max_digit, int *second_max_digit)
{
    return_code_t rc = STATUS_OK;
    int buffer;
    int count = 0;

    while (fscanf(f, "%d", &buffer) == 1)
    {
        count++;
        if (count == 1)
        {
            *max_digit = buffer;
            *second_max_digit = buffer;
        }
        else
        {
            if (buffer > *max_digit)
            {
                *second_max_digit = *max_digit;
                *max_digit = buffer;
            }
            else if (buffer > *second_max_digit && buffer != *max_digit)
                *second_max_digit = buffer;
        }
    }

    if (count < 2)
        rc = STATUS_ANSWER_NOT_FOUND;

    return rc;
}
