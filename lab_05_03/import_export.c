#include "import_export.h"
#include <stdio.h>

return_code_t import_text_to_binary(const char *text_filename, const char *bin_filename)
{
    return_code_t result = STATUS_SUCCESS;
    FILE *fin = NULL;
    FILE *fout = NULL;
    int num;

    fin = fopen(text_filename, "r");
    if (fin == NULL)
        result = STATUS_OPEN_FILE_ERROR;
    else
    {
        fout = fopen(bin_filename, "wb");
        if (fout == NULL)
            result = STATUS_OPEN_FILE_ERROR;

        while (result == STATUS_SUCCESS && fscanf(fin, "%d", &num) == 1)
        {
            if (fwrite(&num, UNIT_SIZE, ELEMENT_COUNT, fout) != 1)
                result = STATUS_WRITE_ERROR;
        }
    }

    if (fin != NULL)
        fclose(fin);
    if (fout != NULL)
        fclose(fout);

    return result;
}

return_code_t export_binary_to_text(const char *bin_filename, const char *text_filename)
{
    return_code_t result = STATUS_SUCCESS;
    FILE *fin = NULL;
    FILE *fout = NULL;
    int num;

    fin = fopen(bin_filename, "rb");
    if (fin == NULL)
        result = STATUS_OPEN_FILE_ERROR;
    else
    {
        fout = fopen(text_filename, "w");
        if (fout == NULL)
            result = STATUS_OPEN_FILE_ERROR;

        while (result == STATUS_SUCCESS && fread(&num, UNIT_SIZE, ELEMENT_COUNT, fin) == 1)
            fprintf(fout, "%d ", num);
    }

    if (fin != NULL)
        fclose(fin);
    if (fout != NULL)
        fclose(fout);

    return result;
}
