#include "file_utils.h"
#include <float.h>

#define EPS 1e-8
#define MAX DBL_MAX

return_code_t count_arithmetic_average(FILE *file, const long start_point, const long end_point, double *sum, int *count)
{
    return_code_t rc = STATUS_SUCCESS;
    double temp = 0.0;

    int parse_status = fscanf(file, "%lf", &temp);
    int current_line = 1;

    while (parse_status != EOF && parse_status != 0 && current_line < end_point)
    {
        if (current_line > start_point)
        {
            *sum += temp;
            *count += 1;
        }

        parse_status = fscanf(file, "%lf", &temp);

        current_line += 1;
    }
    if (*count == 0)
        rc = STATUS_ANSWER_NOT_FOUND;

    return rc;
}

return_code_t find_max_and_min(FILE *file, long *max_pos, long *min_pos)
{
    return_code_t rc = STATUS_SUCCESS;

    double max = -MAX;
    double min = MAX;

    double temp = 0.0;

    int parse_status = fscanf(file, "%lf", &temp);
    int max_state = 0;
    int min_state = 0;
    int current_line = 1;

    while (parse_status != 0 && parse_status != EOF)
    {
        if (temp - max > EPS)
        {
            max = temp;
            max_state = 1;
            *max_pos = current_line;
        }

        if (temp - min < EPS)
        {
            min = temp;
            min_state = 1;
            *min_pos = current_line;
        }

        parse_status = fscanf(file, "%lf", &temp);
        current_line += 1;
    }

    rc = max_state && min_state ? STATUS_SUCCESS : STATUS_MAX_MIN_NOT_FOUND;

    return rc;
}
