#include "file_utils.h"

static void bubble_sort_students_in_file(FILE *file, const size_t file_size);
static int compare_students(student_t *first, student_t *second);
static int is_surname_begin(student_t *student, const char *substr);
static return_code_t compute_average_sum_and_count(FILE *file, double *average, size_t *count);
static return_code_t filter_students_above_average(FILE *src, FILE *dst, double average);
static return_code_t overwrite_file_from_temp(FILE *temp, const char *filename);

return_code_t sort_file(const char *filename)
{
    return_code_t error_code = STATUS_SUCCESS;
    size_t file_size;
    FILE *file;
    student_t temp;

    if (!(file = fopen(filename, "rb+")))
        error_code = STATUS_CANT_OPEN_FILE;

    if (error_code == STATUS_SUCCESS)
    {
        fseek(file, 0, SEEK_END);
        file_size = ftell(file) / sizeof(temp);
        if (file_size == 0)
            error_code = STATUS_EMPTY_FILE;
    }

    if (error_code == STATUS_SUCCESS)
    {
        bubble_sort_students_in_file(file, file_size);

        fseek(file, 0, SEEK_SET);
        for (size_t i = 0; i < file_size; i++)
        {
            fread(&temp, sizeof(temp), ELEMENT_COUNT, file);
            printf("%s\n", temp.surname);
            printf("%s\n", temp.name);
            for (size_t j = 0; j < MARK_COUNT; j++)
                printf("%d\n", temp.marks[j]);
        }

        fclose(file);
    }

    return error_code;
}

return_code_t find_students_in_file(const char *source_filename, const char *dest_filename, const char *substr)
{
    return_code_t error_code = STATUS_SUCCESS;
    size_t file_size;
    size_t found_count = 0;
    FILE *input_file, *output_file;
    student_t student;

    if (!(input_file = fopen(source_filename, "rb")))
        error_code = STATUS_CANT_OPEN_FILE;

    if (error_code == STATUS_SUCCESS && !(output_file = fopen(dest_filename, "wb")))
        error_code = STATUS_CANT_OPEN_FILE;

    if (error_code == STATUS_SUCCESS)
    {
        fseek(input_file, 0, SEEK_END);
        file_size = ftell(input_file) / sizeof(student);
        fseek(input_file, 0, SEEK_SET);
        if (file_size == 0)
            error_code = STATUS_EMPTY_FILE;
    }

    if (error_code == STATUS_SUCCESS)
    {
        for (size_t i = 0; i < file_size; i++)
        {
            fread(&student, sizeof(student), ELEMENT_COUNT, input_file);

            if (is_surname_begin(&student, substr))
            {
                fwrite(&student, sizeof(student), ELEMENT_COUNT, output_file);
                found_count++;
            }
        }

        if (found_count == 0)
            error_code = STATUS_EMPTY_FILE;

        fclose(input_file);
        fclose(output_file);
    }

    return error_code;
}

return_code_t delete_students_in_file(const char *filename)
{
    return_code_t error_code = STATUS_SUCCESS;
    FILE *file = NULL;
    FILE *temp = NULL;
    double average = 0.0;
    size_t count = 0;

    file = fopen(filename, "rb");
    if (file == NULL)
        error_code = STATUS_CANT_OPEN_FILE;

    if (error_code == STATUS_SUCCESS)
        error_code = compute_average_sum_and_count(file, &average, &count);

    if (error_code == STATUS_SUCCESS)
    {
        rewind(file);
        temp = tmpfile();
        if (temp == NULL)
            error_code = STATUS_WRITE_ERROR;
    }

    if (error_code == STATUS_SUCCESS)
        error_code = filter_students_above_average(file, temp, average);

    if (file != NULL)
    {
        fclose(file);
        file = NULL;
    }

    if (error_code == STATUS_SUCCESS)
        error_code = overwrite_file_from_temp(temp, filename);
    if (temp != NULL)
        fclose(temp);

    return error_code;
}

static void bubble_sort_students_in_file(FILE *file, const size_t file_size)
{
    student_t current_i, current_j;

    for (size_t i = 0; i < file_size - 1; i++)
        for (size_t j = i + 1; j < file_size; j++)
        {
            fseek(file, i * sizeof(current_i), SEEK_SET);
            fread(&current_i, sizeof(current_i), ELEMENT_COUNT, file);
            fseek(file, j * sizeof(current_j), SEEK_SET);
            fread(&current_j, sizeof(current_j), ELEMENT_COUNT, file);

            if (compare_students(&current_i, &current_j) > 0)
            {
                fseek(file, i * sizeof(current_j), SEEK_SET);
                fwrite(&current_j, sizeof(current_j), ELEMENT_COUNT, file);
                fseek(file, j * sizeof(current_i), SEEK_SET);
                fwrite(&current_i, sizeof(current_i), ELEMENT_COUNT, file);
            }
        }
}

static return_code_t compute_average_sum_and_count(FILE *file, double *average, size_t *count)
{
    student_t s;
    double total_sum = 0.0;
    size_t n = 0;
    return_code_t err = STATUS_SUCCESS;

    while (err == STATUS_SUCCESS && fread(&s, sizeof(s), 1, file) == 1)
    {
        double sum = 0.0;
        for (int i = 0; i < MARK_COUNT; i++)
            sum += s.marks[i];
        total_sum += sum;
        n++;
    }

    if (n == 0)
        err = STATUS_EMPTY_FILE;
    else
    {
        *average = total_sum / n;
        *count = n;
    }
    return err;
}

static return_code_t filter_students_above_average(FILE *src, FILE *dst, double average)
{
    student_t s;
    return_code_t err = STATUS_SUCCESS;

    rewind(src);
    while (err == STATUS_SUCCESS && fread(&s, sizeof(s), 1, src) == 1)
    {
        double sum = 0.0;
        for (int i = 0; i < MARK_COUNT; i++)
            sum += s.marks[i];
        if (sum >= average)
        {
            if (fwrite(&s, sizeof(s), 1, dst) != 1)
                err = STATUS_WRITE_ERROR;
        }
    }
    return err;
}

static return_code_t overwrite_file_from_temp(FILE *temp, const char *filename)
{
    FILE *dest = fopen(filename, "wb");

    student_t s;
    return_code_t err = STATUS_SUCCESS;
    rewind(temp);

    while (err == STATUS_SUCCESS && fread(&s, sizeof(s), 1, temp) == 1)
    {
        if (fwrite(&s, sizeof(s), 1, dest) != 1)
            err = STATUS_WRITE_ERROR;
    }

    fclose(dest);
    return err;
}

static int compare_students(student_t *first, student_t *second)
{
    int result = strncmp(first->surname, second->surname, MAX_SURNAME_LENGTH);

    if (result == 0)
        result = strncmp(first->name, second->name, MAX_NAME_LENGTH);

    return result;
}

static int is_surname_begin(student_t *student, const char *substr)
{
    return strncmp(student->surname, substr, strlen(substr)) == 0;
}
