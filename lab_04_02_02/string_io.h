#ifndef STRING_IO_H
#define STRING_IO_H
#include "status.h"
#define MAX_SENTENCE_LENGTH 256

return_code_t input_string(const char *prompt, char *str);
void print_error_message(return_code_t rc);

#endif
