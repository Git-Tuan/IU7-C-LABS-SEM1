#include "matrix_io.h"
#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

int main(void)
{
    matrix mat;
    int primes[MAX * MAX];

    status_code rc = read_size(&mat.row_count, &mat.col_count);

    if (rc == STATUS_OK)
        rc = read_matrix(&mat);

    if (rc == STATUS_OK)
    {
        int count = collect_primes(&mat, primes);

        if (count == 0)
            rc = NO_PRIMES;
        else
        {
            reverse_array(primes, count);
            put_back(&mat, primes);
            print_matrix(&mat);
        }
    }

    return rc;
}
