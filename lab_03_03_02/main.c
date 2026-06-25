#include <stdio.h>
#include "status.h"
#include "matrix_io.h"
#include "matrix_utils.h"

#define MAX 10

int main(void)
{
    matrix mat;

    status_code rc = read_size(&mat.row_count, &mat.col_count);

    if (rc == STATUS_OK)
        rc = read_matrix(&mat);

    if (rc == STATUS_OK)
    {
        sort_rows_by_product(&mat);
        print_matrix(&mat);
    }

    return rc;
}
