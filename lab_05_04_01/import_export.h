#ifndef IMPORT_EXPORT_H
#define IMPORT_EXPORT_H

#include "file_utils.h"
#include "status.h"

#define MAX_SURNAME_LENGTH 26
#define MAX_NAME_LENGTH 11
#define MARK_COUNT 4

return_code_t import_text_to_binary(char *text_filename, char *bin_filename);
return_code_t export_binary_to_text(char *bin_filename, char *text_filename);

#endif
