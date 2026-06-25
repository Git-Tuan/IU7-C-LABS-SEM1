#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H
#define MAX_SENTENCE_LENGTH 258
#define MAX_WORD_LENGTH 16
#include "status.h"

return_code_t check_day(const char *day, int month, int is_leap);
void split_words(const char *sentence, char words[][MAX_WORD_LENGTH], int *count);
int check_month(char *month, int length);
return_code_t check_year(const char *year, int *is_leap);

#endif
