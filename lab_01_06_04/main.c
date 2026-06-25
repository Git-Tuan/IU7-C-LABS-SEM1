#include <stdio.h>
#include <math.h>
#define EPS 1e-8

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR,
    STATUS_SEGMENT_NOT_FORMED
} return_code_t;

int is_point_on_segment(double xq, double yq, double xr, double yr, double xp, double yp);
int input_coordinates(const char *prompt, double *x, double *y);
void print_result(int point_on_segment);
int check_segment_validity(double xq, double yq, double xr, double yr);
void print_error_messages(return_code_t error_code);

int main(void)
{
    double xq, yq, xr, yr, xp, yp;
    return_code_t status = input_coordinates("Enter coordinates for the q dot: ", &xq, &yq);

    if (status == STATUS_OK)
        status = input_coordinates("Enter coordinates for the r dot: ", &xr, &yr);
    if (status == STATUS_OK)
        status = check_segment_validity(xq, yq, xr, yr);
    if (status == STATUS_OK)
        status = input_coordinates("Enter coordinates for the p dot: ", &xp, &yp);
    if (status == STATUS_OK)
    {
        int point_on_segment = is_point_on_segment(xq, yq, xr, yr, xp, yp);
        print_result(point_on_segment);
    }
    if (status != STATUS_OK)
        print_error_messages(status);

    return status;
}

int input_coordinates(const char *prompt, double *x, double *y)
{
    return_code_t rc = STATUS_OK;

    printf("%s", prompt);
    int inp = scanf("%lf%lf", x, y) == 2;
    if (!(inp))
        rc = STATUS_INPUT_ERROR;

    return rc;
}

int check_segment_validity(double xq, double yq, double xr, double yr)
{
    int form_segment = !(fabs(xq - xr) < EPS && fabs(yq - yr) < EPS);
    return_code_t rc = STATUS_OK;

    if (!(form_segment))
        rc = STATUS_SEGMENT_NOT_FORMED;

    return rc;
}

void print_result(int point_on_segment)
{
    if (point_on_segment == 1)
        printf("P belongs to the segment: 1");
    else
        printf("P doesn't belong to the segment: 0");
}

void print_error_messages(return_code_t error_code)
{
    if (error_code == STATUS_INPUT_ERROR)
        printf("Error: Incorrect format of coordinates\n");
    if (error_code == STATUS_SEGMENT_NOT_FORMED)
        printf("Error: The segment can't be formed");
}

int is_point_on_segment(double xq, double yq, double xr, double yr, double xp, double yp)
{
    int result = 0;
    double det = (xr - xq) * (yp - yq) - (yr - yq) * (xp - xq);

    if (fabs(det) < EPS)
    {
        double min_x = fmin(xq, xr) - EPS;
        double max_x = fmax(xq, xr) + EPS;
        double min_y = fmin(yq, yr) - EPS;
        double max_y = fmax(yq, yr) + EPS;

        if (xp >= min_x && xp <= max_x && yp >= min_y && yp <= max_y)
            result = 1;
    }

    return result;
}
