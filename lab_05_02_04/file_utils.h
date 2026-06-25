#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "status.h"
#include <stdio.h>

return_code_t find_max_and_min(FILE *file, long *max_pos, long *min_pos);
return_code_t count_arithmetic_average(FILE *file, const long start_point, const long end_point, double *sum, int *count);

#endif
