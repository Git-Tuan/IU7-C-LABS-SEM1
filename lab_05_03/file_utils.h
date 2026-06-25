#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "import_export.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_SIZE sizeof(int)
#define ELEMENT_COUNT 1

return_code_t get_mode(const int argc, char **argv, char *mode);
return_code_t process_mode(char **argv, const char mode);

#endif
