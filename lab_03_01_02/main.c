#include <stdio.h>
#include "arr_o.h"
#include "matrix_io.h"
#include "matrix_utils.h"
#include "status.h"

int main(void)
{
    status_code status = STATUS_OK;

    matrix mat;

    int result[MAX] = 
    {
        0
    };

    status = read_size(&mat.row_count, &mat.col_count);

    if (status == STATUS_OK)
        status = read_matrix(&mat);

    if (status == STATUS_OK)
    {
        if (mat.row_count < 2)
            print_array(result, mat.col_count);
        else
        {
            build_result(&mat, result);
            print_array(result, mat.col_count);
        }
    }

    return status;
}
