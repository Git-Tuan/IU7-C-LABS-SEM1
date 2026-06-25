#include <stdio.h>

typedef enum
{
    STATUS_OK = 0,
    STATUS_FAIL = 1
} return_code_t;

void print_prime_factors(int n);
int input(int *n);

int main(void)
{
    int n;
    int input_status = STATUS_OK;

    printf("Enter N: ");
    input_status = input(&n);
    
    if (input_status == STATUS_OK)
    {
        if (n != 1)
            print_prime_factors(n);
    }
    return input_status;
}

int input(int *n)
{   
    int rc = STATUS_OK;
    
    if (scanf("%d", n) != 1 || *n < 1)
    {
        rc = STATUS_FAIL;
    }
    return rc;
}

void print_prime_factors(int n)
{
    int first = 1;

    for (int i = 2; i <= n; i++)
    {   
        for (; n % i == 0; n /= i)
        {
            if (!first)
                printf(" ");

            printf("%d", i);
            first = 0;
        }
    }
}

