#include "status.h"
#include "string_funcs.h"
#include "string_io.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    return_code_t rc = STATUS_SUCCESS;

    char sentence_1[MAX_SENTENCE_LENGTH];
    char sentence_2[MAX_SENTENCE_LENGTH];

    char words1[MAX_WORDS][MAX_WORD_LENGTH];
    char words2[MAX_WORDS][MAX_WORD_LENGTH];

    int count1 = 0;
    int count2 = 0;

    rc = input_string("Введите 1-ую строку: ", sentence_1);

    if (rc == STATUS_SUCCESS)
        rc = input_string("Введите 2-ую строку: ", sentence_2);
    if (rc == STATUS_SUCCESS)
    {
        split_words(sentence_1, words1, &count1);
        split_words(sentence_2, words2, &count2);
    }
    if (rc == STATUS_SUCCESS)
        compare_sentences(words1, count1, words2, count2);

    print_error_message(rc);

    return rc;
}
