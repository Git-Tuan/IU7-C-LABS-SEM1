#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "status.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SURNAME_LENGTH 26
#define MAX_NAME_LENGTH 11
#define MARK_COUNT 4
#define ELEMENT_COUNT 1

typedef struct
{
    char surname[MAX_SURNAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    uint32_t marks[MARK_COUNT];
} student_t;

return_code_t sort_file(const char *filename);
return_code_t find_students_in_file(const char *source_filename, const char *dest_filename, const char *substr);
return_code_t delete_students_in_file(const char *filename);

#endif
