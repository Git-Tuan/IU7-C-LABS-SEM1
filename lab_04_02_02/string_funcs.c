#include "string_funcs.h"
#include <stdio.h>

void compare_sentences(char words1[][MAX_WORD_LENGTH], int count1, char words2[][MAX_WORD_LENGTH], int count2)
{
    printf("Result:\n");

    for (int i = 0; i < count1; i++)
    {
        int is_duplicate = 0;

        for (int k = 0; k < i && !is_duplicate; k++)
        {
            if (strcmp(words1[i], words1[k]) == 0)
                is_duplicate = 1;
        }

        if (!is_duplicate)
        {
            int found = 0;

            for (int j = 0; j < count2 && !found; j++)
            {
                if (strcmp(words1[i], words2[j]) == 0)
                    found = 1;
            }

            if (found)
                printf("%s yes\n", words1[i]);
            else
                printf("%s no\n", words1[i]);
        }
    }
}

static int is_delim(char c)
{
    return c == ' ' || c == ',' || c == ';' || c == ':' || c == '-' || c == '.' || c == '!' || c == '?' || c == '\n';
}

void split_words(char *sentence, char words[][MAX_WORD_LENGTH], int *count)
{
    int letter_index = 0;
    int inside_word = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (is_delim(sentence[i]))
        {
            if (inside_word)
            {
                words[*count][letter_index] = '\0';

                (*count)++;

                letter_index = 0;
                inside_word = 0;
            }
        }
        else
        {
            words[*count][letter_index] = sentence[i];
            letter_index++;
            inside_word = 1;
        }
    }
}
