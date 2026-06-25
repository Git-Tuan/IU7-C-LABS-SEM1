#include "import_export.h"
#include <stdio.h>

return_code_t import_text_to_binary(char *text_filename, char *bin_filename)
{
    return_code_t res = STATUS_SUCCESS;
    FILE *fin = NULL;
    FILE *fout = NULL;

    fin = fopen(text_filename, "r");
    if (fin != NULL)
    {
        fout = fopen(bin_filename, "wb");
        if (fout != NULL)
        {
            student_t s;
            while (res == STATUS_SUCCESS && fscanf(fin, "%25s", s.surname) == 1)
            {
                if (fscanf(fin, "%10s", s.name) != 1)
                    res = STATUS_WRITE_ERROR;

                if (res == STATUS_SUCCESS &&
                    fscanf(fin, "%u %u %u %u", &s.marks[0], &s.marks[1], &s.marks[2], &s.marks[3]) != 4)
                    res = STATUS_WRITE_ERROR;

                if (res == STATUS_SUCCESS && fwrite(&s, sizeof(student_t), 1, fout) != 1)
                    res = STATUS_WRITE_ERROR;
            }
            fclose(fout);
        }
        else
            res = STATUS_CANT_OPEN_FILE;

        fclose(fin);
    }
    else
        res = STATUS_CANT_OPEN_FILE;

    return res;
}

return_code_t export_binary_to_text(char *bin_filename, char *text_filename)
{
    return_code_t res = STATUS_SUCCESS;
    FILE *fin = NULL;
    FILE *fout = NULL;

    fin = fopen(bin_filename, "rb");
    if (fin != NULL)
    {
        fout = fopen(text_filename, "w");
        if (fout != NULL)
        {
            student_t s;
            while (res == STATUS_SUCCESS && fread(&s, sizeof(student_t), 1, fin) == 1)
            {
                fprintf(fout, "%s\n%s\n", s.surname, s.name);
                for (int i = 0; i < MARK_COUNT; i++)
                    fprintf(fout, "%d\n", s.marks[i]);
            }
            fclose(fout);
        }
        else
            res = STATUS_CANT_OPEN_FILE;

        fclose(fin);
    }
    else
        res = STATUS_CANT_OPEN_FILE;

    return res;
}
