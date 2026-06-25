#include "matrix_io.h"
#include "matrix_utils.h"
#include "status.h"
#include <stdio.h>

int main(void)
{
    matrix mat;
    status_code status = STATUS_OK;

    status = read_size(&mat.row_count, &mat.col_count);

    if (status == STATUS_OK)
    {
        for (int i = 0; i < MAX; i++)
            mat.rows[i] = mat.data[i];

        status = read_matrix(&mat);
    }

    if (status == STATUS_OK)
    {
        int new_row;
        status = insert_rows(&mat, &new_row);
        if (status != STATUS_INSERT_NO_SPACE_ERROR)
        {
            mat.row_count = new_row;
            print_matrix(&mat);
        }
    }

    return status;
}
