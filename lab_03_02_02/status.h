#ifndef STATUS_H
#define STATUS_H

typedef enum
{
    STATUS_OK = 0,
    STATUS_INPUT_ERROR = 1,
    STATUS_SIZE_ERROR = 2,
    STATUS_INSERT_NO_SPACE_ERROR = 3
} status_code;

#endif
