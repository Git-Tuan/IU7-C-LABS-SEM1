#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include "status.h"
#include <string.h>
#define MAX_SENTENCE_LENGTH 256
#define MAX_WORDS 128
#define MAX_WORD_LENGTH 16

void compare_sentences(char words1[][MAX_WORD_LENGTH], int count1, char words2[][MAX_WORD_LENGTH], int count2);
void split_words(char *sentence, char words[][MAX_WORD_LENGTH], int *count);

#endif
