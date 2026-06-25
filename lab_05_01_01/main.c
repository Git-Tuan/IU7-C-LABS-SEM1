#include "file_utils.h"
#include <stdio.h>

int main(void)
{
    return_code_t rc = STATUS_OK;
    int max_digit, second_max_digit;

    printf("Введите числа:\n");
    rc = process(stdin, &max_digit, &second_max_digit);

    if (rc == STATUS_OK)
        print_result(max_digit, second_max_digit);
    else
        printf("Не удалось получить ответ\n");

    return rc;
}
