#include <math.h>
#include <stdio.h>

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_NO_NUMBERS = 2
} return_code_t;

int verify_input(int inp);
float g(float x, int n);
int input_float(float *value);
int process_numbers(float *summ, int *count);
void print_result(float summ, int count);
void print_error_messages(return_code_t error_code);

int main(void)
{
    float summ = 0;
    int count = 0;
    return_code_t code = 0;

    if (!process_numbers(&summ, &count))
        code = STATUS_INPUT_ERROR;
    else if (count == 0)
        code = STATUS_NO_NUMBERS;
    else
        print_result(summ, count);
    if (code != STATUS_OK)
        print_error_messages(code);

    return code;
}

int process_numbers(float *summ, int *count)
{
    float x = 0;
    int code = 1;

    if (!input_float(&x))
    {
        code = 0;
    }

    for (; x >= 0 && code == 1;)
    {
        (*count)++;
        *summ += g(x, *count);

        if (!input_float(&x))
        {
            code = 0;
        }
    }

    return code;
}

int input_float(float *value)
{
    return verify_input(scanf("%f", value));
}

int verify_input(int inp)
{
    return inp == 1;
}

void print_result(float summ, int count)
{
    float average = summ / count;
    printf("%f", average);
}

float g(float x, int n)
{
    return sqrt(n + x);
}

void print_error_messages(return_code_t error_code)
{
    if (error_code == STATUS_NO_NUMBERS)
        printf("Error: numbers weren't given");
    else if (error_code == STATUS_INPUT_ERROR)
        printf("Invalid input");
}
