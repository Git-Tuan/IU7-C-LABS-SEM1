#include "status.h"
#include "string_funcs.h"
#include "string_io.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    return_code_t rc = STATUS_SUCCESS;

    char buffer[MAX_SENTENCE_LENGTH];
    char new_buffer[MAX_SENTENCE_LENGTH];

    rc = input_string("Введите строку: ", buffer);

    if (rc == STATUS_SUCCESS)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        form_new_sentence(buffer, new_buffer);

        if (new_buffer[0] != '\0')
            print_result(new_buffer);
    }

    print_error_message(rc);

    return rc;
}
