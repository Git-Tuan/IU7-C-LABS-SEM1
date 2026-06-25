#include "file_utils.h"
#include "status.h"
#include <float.h>
#include <stdio.h>

void print_error_message(return_code_t rc);

int main(int argc, char *argv[])
{
    return_code_t rc = STATUS_SUCCESS;
    double sum = 0.0;
    int count = 0;
    long max_pos;
    long min_pos;

    if (argc != 2)
        rc = STATUS_INPUT_ERROR;

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
        rc = STATUS_FILE_NOT_FOUND;
    if (rc == STATUS_SUCCESS)
        rc = find_max_and_min(file, &max_pos, &min_pos);
    if (rc == STATUS_SUCCESS)
    {
        long start_point = max_pos > min_pos ? min_pos : max_pos;
        long end_point = max_pos > min_pos ? max_pos : min_pos;
        rewind(file);
        rc = count_arithmetic_average(file, start_point, end_point, &sum, &count);
    }

    if (rc == STATUS_SUCCESS)
        printf("%lf\n", sum / count);
    else
        print_error_message(rc);

    if (file)
        fclose(file);

    return rc;
}

void print_error_message(return_code_t rc)
{
    if (rc == STATUS_INPUT_ERROR)
        printf("Ошибка: неправильный формат аргументов\n");
    else if (rc == STATUS_FILE_NOT_FOUND)
        printf("Ошибка: не удалось открыть файл\n");
    else if (rc == STATUS_ANSWER_NOT_FOUND)
        printf("Ошибка: не удалось получить ответ\n");
    else if (rc == STATUS_MAX_MIN_NOT_FOUND)
        printf("Ошибка: максимум и второй максимум не найдены\n");
}
