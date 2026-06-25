#include "string_io.h"
#include <stdio.h>
#include <string.h>
#define MAX_SENTENCE_LENGTH 258

return_code_t input_string(char *str)
{
    return_code_t status = STATUS_SUCCESS;
    char *result = fgets(str, MAX_SENTENCE_LENGTH, stdin);

    if (result == NULL)
    {
        str[0] = '\0';
        status = STATUS_SUCCESS;
    }
    else
    {
        size_t len = strlen(str);
        if (len == MAX_SENTENCE_LENGTH - 1 && str[len - 1] != '\n')
            status = STATUS_SENTENCE_LENGTH_ERROR;
        else
        {
            if (len > 0 && str[len - 1] == '\n')
                str[--len] = '\0';
        }
    }
    return status;
}
