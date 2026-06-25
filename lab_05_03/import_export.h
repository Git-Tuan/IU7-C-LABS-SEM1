#ifndef IMPORT_EXPORT_H
#define IMPORT_EXPORT_H

#include "status.h"
#define UNIT_SIZE sizeof(int)
#define ELEMENT_COUNT 1

return_code_t import_text_to_binary(const char *text_filename, const char *bin_filename);
return_code_t export_binary_to_text(const char *bin_filename, const char *text_filename);

#endif
