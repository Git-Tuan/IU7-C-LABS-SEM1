#include "matrix_io.h"
#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

int main(void)
{
    matrix mat;
    int max;

    status_code rc = read_size(&mat.row_count, &mat.col_count);

    if (rc == STATUS_OK)
        rc = read_matrix(&mat);

    if (rc == STATUS_OK)
    {
        int found = find_max(&mat, &max);

        if (!found)
        {
            printf("Нет подходящих элементов\n");
            rc = NOT_FOUND_ERROR;
        }
        else
            printf("%d\n", max);
    }

    return rc;
}
