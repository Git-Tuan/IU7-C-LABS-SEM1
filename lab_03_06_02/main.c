#include "matrix_io.h"
#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

int main(void)
{
    matrix mat;

    status_code rc = read_size(&mat.row_count, &mat.col_count);

    if (rc == STATUS_OK)
    {
        fill_matrix(&mat);
        print_matrix(&mat);
    }

    return rc;
}
