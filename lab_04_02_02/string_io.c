#include "string_io.h"
#include "status.h"
#include "string_funcs.h"
#include <stdio.h>

return_code_t input_string(const char *prompt, char *str)
{
    return_code_t status = STATUS_SUCCESS;

    printf("%s", prompt);

    char *result = fgets(str, MAX_SENTENCE_LENGTH, stdin);

    if (result == NULL)
        status = STATUS_INPUT_ERROR;
    else if (str[0] == '\n' || str[0] == '\0')
        status = STATUS_INPUT_ERROR;
    else if (strchr(str, '\n') == NULL)
        status = STATUS_SENTENCE_LENGTH_ERROR;

    return status;
}

void print_error_message(return_code_t rc)
{
    if (rc == STATUS_INPUT_ERROR) 
    {
        printf("Error: invalid format of the input\n");
    } 
    else if (rc == STATUS_SENTENCE_LENGTH_ERROR) 
    {
        printf("Error: input sentence exceeded max length\n");
    } 
}
