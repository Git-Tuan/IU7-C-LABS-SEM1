#include "file_utils.h"
#include "import_export.h"
#include "status.h"
#include <stdio.h>

#define MAX_SURNAME_LENGTH 26
#define MAX_NAME_LENGTH 11
#define MARK_COUNT 4
#define ELEMENT_COUNT 1

void print_error_message(return_code_t rc);

int main(int argc, char **argv)
{
    return_code_t rc = STATUS_SUCCESS;

    if (argc < 3 || argc > 5)
        rc = STATUS_INCORRECT_ARGS;

    if (rc == STATUS_SUCCESS)
    {
        if (strncmp(argv[1], "sb", 2) == 0 && argc == 3)
            rc = sort_file(argv[2]);
        else if (strncmp(argv[1], "fb", 2) == 0 && argc == 5)
            rc = find_students_in_file(argv[2], argv[3], argv[4]);
        else if (strncmp(argv[1], "db", 2) == 0 && argc == 3)
            rc = delete_students_in_file(argv[2]);
        else if (strcmp(argv[1], "import") == 0 && argc == 4)
            rc = import_text_to_binary(argv[2], argv[3]);
        else if (strcmp(argv[1], "export") == 0 && argc == 4)
            rc = export_binary_to_text(argv[2], argv[3]);
        else
            rc = STATUS_INCORRECT_ARGS;
    }
    else
        print_error_message(rc);

    return rc;
}

void print_error_message(return_code_t rc)
{
    if (rc == STATUS_INCORRECT_ARGS)
        printf("Ошибка: неверные аргументы\n");
    else if (rc == STATUS_CANT_OPEN_FILE)
        printf("Ошибка: не удалось открыть файл\n");
    else if (rc == STATUS_EMPTY_FILE)
        printf("Ошибка: файл пуст\n");
    else if (rc == STATUS_WRITE_ERROR)
        printf("Ошибка: ошибка записи\n");
    else if (rc == STATUS_OPEN_FILE_ERROR)
        printf("Ошибка: ошибка открытия файла\n");
}
