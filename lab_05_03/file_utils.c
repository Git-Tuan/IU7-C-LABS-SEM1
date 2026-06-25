#include "file_utils.h"

static return_code_t get_file_size(FILE *file, int *size);
static return_code_t put_number_by_pos(FILE *file, int number, const int position);
static return_code_t get_number_by_pos(FILE *file, const int position, int *number);
static return_code_t read_binary_file(const char *filename);
static return_code_t fill_with_random_nums(const char *filename, const int count);
static return_code_t bubble_sort(FILE *file, const int count);
static return_code_t sort_file(const char *filename);

return_code_t get_mode(const int argc, char **argv, char *mode)
{
    return_code_t result;

    if (argc < 3 || argc > 4)
        result = STATUS_WRONG_MAIN_ARGS;
    else if (!strcmp(argv[1], "f"))
    {
        if (argc != 4)
            result = STATUS_WRONG_MAIN_ARGS;
        else
        {
            *mode = 'f';
            result = STATUS_SUCCESS;
        }
    }
    else if (!strcmp(argv[1], "p"))
    {
        *mode = 'p';
        result = STATUS_SUCCESS;
    }
    else if (!strcmp(argv[1], "s"))
    {
        *mode = 's';
        result = STATUS_SUCCESS;
    }
    else if (!strcmp(argv[1], "import"))
    {
        if (argc != 4)
            result = STATUS_WRONG_MAIN_ARGS;
        else
        {
            *mode = 'i';
            result = STATUS_SUCCESS;
        }
    }
    else if (!strcmp(argv[1], "export"))
    {
        if (argc != 4)
            result = STATUS_WRONG_MAIN_ARGS;
        else
        {
            *mode = 'e';
            result = STATUS_SUCCESS;
        }
    }
    else
        result = STATUS_WRONG_MODE;

    return result;
}

return_code_t process_mode(char **argv, const char mode)
{
    return_code_t error_code = STATUS_SUCCESS;

    if (mode == 'f')
    {
        if (atoi(argv[2]) < 1)
            error_code = STATUS_FILL_FILE_ERROR;
        else
            error_code = fill_with_random_nums(argv[3], atoi(argv[2]));
    }
    else if (mode == 'p')
        error_code = read_binary_file(argv[2]);
    else if (mode == 's')
        error_code = sort_file(argv[2]);
    else if (mode == 'i')
        error_code = import_text_to_binary(argv[2], argv[3]);
    else if (mode == 'e')
        error_code = export_binary_to_text(argv[2], argv[3]);

    return error_code;
}

static return_code_t get_file_size(FILE *file, int *size)
{
    return_code_t result;

    if (fseek(file, 0L, SEEK_END))
        result = STATUS_SEEK_ERROR;
    else
    {
        long pos = ftell(file);

        if (fseek(file, 0L, SEEK_SET))
            result = STATUS_SEEK_ERROR;
        else if (pos % UNIT_SIZE || pos < (long)UNIT_SIZE)
            result = STATUS_FILE_SIZE_ERROR;
        else
        {
            *size = pos / UNIT_SIZE;
            result = STATUS_SUCCESS;
        }
    }

    return result;
}

static return_code_t put_number_by_pos(FILE *file, int number, const int position)
{
    return_code_t result;
    int count;

    if (get_file_size(file, &count) || position >= count)
        result = STATUS_FILE_SIZE_ERROR;
    else if (fseek(file, UNIT_SIZE * position, SEEK_SET))
        result = STATUS_SEEK_ERROR;
    else if (fwrite(&number, UNIT_SIZE, ELEMENT_COUNT, file) != ELEMENT_COUNT)
        result = STATUS_WRITE_ERROR;
    else
    {
        rewind(file);
        result = STATUS_SUCCESS;
    }

    return result;
}

static return_code_t get_number_by_pos(FILE *file, const int position, int *number)
{
    return_code_t result;
    int count;

    if (get_file_size(file, &count) || position >= count)
        result = STATUS_FILE_SIZE_ERROR;
    else if (fseek(file, UNIT_SIZE * position, SEEK_SET))
        result = STATUS_SEEK_ERROR;
    else if (fread(number, UNIT_SIZE, ELEMENT_COUNT, file) != ELEMENT_COUNT)
        result = STATUS_READ_ERROR;
    else
    {
        rewind(file);
        result = STATUS_SUCCESS;
    }

    return result;
}

static return_code_t read_binary_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    return_code_t result;

    if (!file)
        result = STATUS_OPEN_FILE_ERROR;
    else
    {
        int current;
        int count;

        if (get_file_size(file, &count))
            result = STATUS_FILE_SIZE_ERROR;
        else
        {
            while (fread(&current, UNIT_SIZE, ELEMENT_COUNT, file) == ELEMENT_COUNT)
                printf("%d ", current);

            if (fclose(file))
                result = STATUS_FILE_CLOSE_ERROR;
            else
                result = STATUS_SUCCESS;
        }
    }

    return result;
}

static return_code_t fill_with_random_nums(const char *filename, const int count)
{
    FILE *file = fopen(filename, "wb");
    return_code_t result;
    int i = 0;

    if (!file)
        result = STATUS_OPEN_FILE_ERROR;
    else
    {
        for (; i < count && result != STATUS_WRITE_ERROR; i++)
        {
            int number = rand() % 100;
            if (fwrite(&number, UNIT_SIZE, ELEMENT_COUNT, file) != ELEMENT_COUNT)
                result = STATUS_WRITE_ERROR;
        }

        if (i == count && result != STATUS_WRITE_ERROR)
        {
            if (fclose(file))
                result = STATUS_FILE_CLOSE_ERROR;
            else
                result = STATUS_SUCCESS;
        }
    }

    return result;
}

static return_code_t bubble_sort(FILE *file, const int count)
{
    int i, j;
    int sorted = 1;
    return_code_t rc = STATUS_SUCCESS;

    for (i = 0; i < count - 1 && sorted && rc == STATUS_SUCCESS; i++)
    {
        sorted = 0;

        for (j = 0; j < count - i - 1 && rc == STATUS_SUCCESS; j++)
        {
            int a, b;
            get_number_by_pos(file, j, &a);
            get_number_by_pos(file, j + 1, &b);

            if (a > b)
            {
                rc = put_number_by_pos(file, b, j);
                if (rc == STATUS_SUCCESS)
                    rc = put_number_by_pos(file, a, j + 1);
                if (rc == STATUS_SUCCESS)
                    sorted = 1;
            }
        }
    }

    return rc;
}

static return_code_t sort_file(const char *filename)
{
    FILE *file = fopen(filename, "rb+");
    return_code_t result;
    int count;
    int rc;

    if ((rc = get_file_size(file, &count)))
        result = rc;
    else
        result = bubble_sort(file, count);
    if (fclose(file))
        result = STATUS_FILE_CLOSE_ERROR;

    return result;
}
