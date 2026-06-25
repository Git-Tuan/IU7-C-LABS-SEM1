#ifndef STATUS_H
#define STATUS_H

typedef enum
{
    STATUS_SUCCESS = 0,
    STATUS_INCORRECT_ARGS = 53,
    STATUS_CANT_OPEN_FILE = 2,
    STATUS_EMPTY_FILE = 3,
    STATUS_WRITE_ERROR = 4,
    STATUS_OPEN_FILE_ERROR = 5
} return_code_t;

#endif
