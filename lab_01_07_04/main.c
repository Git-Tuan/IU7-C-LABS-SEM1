#include <math.h>
#include <stdio.h>

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_X_ERROR = 2,
    STATUS_EPS_ERROR = 3
} return_code_t;

int verify_input(int r);
int input_double(const char *prompt, double *value);
int check_x(double x);
int check_eps(double eps);
void print_results(double sval, double fval, double absolute_error, double relative_error);
double f(double x);
double s(double x, double eps);
void print_error_messages(return_code_t error_code);

int main(void)
{
    double x, eps;
    double sval, fval;
    double absolute_error, relative_error;
    return_code_t status = STATUS_OK;

    if (!input_double("Enter x: ", &x))
        status = STATUS_INPUT_ERROR;

    if (status == STATUS_OK && !check_x(x))
        status = STATUS_X_ERROR;

    if (status == STATUS_OK && !input_double("Enter epsilon: ", &eps))
        status = STATUS_INPUT_ERROR;

    if (status == STATUS_OK && !check_eps(eps))
        status = STATUS_EPS_ERROR;

    if (status == STATUS_OK)
    {
        sval = s(x, eps);
        fval = f(x);
        absolute_error = fabs(fval - sval);
        relative_error = absolute_error / fabs(fval);
    }

    if (status != STATUS_OK)
        print_error_messages(status);
    else
        print_results(sval, fval, absolute_error, relative_error);

    return status;
}

int verify_input(int r)
{
    return r == 1;
}

int input_double(const char *prompt, double *value)
{
    printf("%s", prompt);
    return verify_input(scanf("%lf", value));
}

int check_x(double x)
{
    int code = 1;
    if (fabs(x) >= 1)
    {
        printf("|X| must be less than 1 \n");
        code = 0;
    }

    return code;
}

int check_eps(double eps)
{
    int code = 1;
    if (eps <= 0 || eps > 1)
    {
        printf("epsilon must satisfy 0 < eps <= 1\n");
        code = 0;
    }
    return code;
}

void print_results(double sval, double fval, double absolute_error, double relative_error)
{
    printf("S(x) = %f\n", sval);
    printf("F(x) = %f\n", fval);
    printf("Absolute status = %f\n", absolute_error);
    printf("Relative status = %f\n", relative_error);
}

double f(double x)
{
    return 1.0 / pow(1 + x, 3);
}

double s(double x, double eps)
{
    double sum = 0;
    double term;
    int n = 0;

    do
    {
        term = pow(-1, n) * (n + 1) * (n + 2) * pow(x, n) / 2.0;

        if (fabs(term) >= eps)
        {
            sum += term;
        }
        n++;
    } while (fabs(term) >= eps);

    return sum;
}

void print_error_messages(return_code_t error_code)
{
    if (error_code == STATUS_INPUT_ERROR)
        printf("Input status\n");
    else if (error_code == STATUS_X_ERROR)
        printf("x out of range\n");
    else if (error_code == STATUS_EPS_ERROR)
        printf("epsilon out of range\n");
}
