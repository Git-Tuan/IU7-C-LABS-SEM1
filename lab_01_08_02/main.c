#include <stdio.h>

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_NEGATIVE_N = 2
} return_code_t;

void converter(unsigned int a);
unsigned int rotate_left(unsigned int a, int n);
int input_unsigned(const char *prompt, unsigned int *value);
int input_int(const char *prompt, int *value);
int check_n_positive(int n);
void print_result(unsigned int res);
void print_error_messages(return_code_t error_code);

int main(void)
{
    unsigned int a;
    int n;
    return_code_t status = STATUS_OK;
    unsigned int res = 0;

    if (!input_unsigned("Enter A: ", &a))
        status = STATUS_INPUT_ERROR;
    else if (!input_int("Enter N: ", &n))
        status = STATUS_INPUT_ERROR;
    else if (!check_n_positive(n))
        status = STATUS_NEGATIVE_N;
    else
        res = rotate_left(a, n);

    if (status != STATUS_OK)
        print_error_messages(status);
    else
        print_result(res);

    return status;
}

int input_unsigned(const char *prompt, unsigned int *value)
{
    printf("%s", prompt);
    return scanf("%u", value) == 1;
}

int input_int(const char *prompt, int *value)
{
    printf("%s", prompt);
    return scanf("%d", value) == 1;
}

int check_n_positive(int n)
{
    return n >= 0;
}

void print_result(unsigned int res)
{
    printf("Result: ");
    converter(res);
}

void converter(unsigned int a)
{
    for (int i = 8 * sizeof(unsigned int) - 1; i >= 0; i--)
    {
        printf("%u", (a >> i) & 1);
    }
}

unsigned int rotate_left(unsigned int a, int n)
{
    unsigned int result;

    n %= 8 * sizeof(unsigned int);
    if (n == 0)
    {
        result = a;
    }
    else
    {
        result = (a << n) | (a >> (8 * sizeof(unsigned int) - n));
    }

    return result;
}

void print_error_messages(return_code_t error_code)
{
    if (error_code == STATUS_INPUT_ERROR)
        printf("Error: the input value is not a number");
    else if (error_code == STATUS_NEGATIVE_N)
        printf("Error: n is negative");
}
