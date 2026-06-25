#include "file_utils.h"
#include "status.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char mode;
    return_code_t rc;

    rc = get_mode(argc, argv, &mode);

    if (rc == STATUS_SUCCESS)
        rc = process_mode(argv, mode);

    return rc;
}
