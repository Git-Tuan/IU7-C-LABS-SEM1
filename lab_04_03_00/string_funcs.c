#include "string_funcs.h"
#include <stdio.h>
#include <string.h>

static int split_to_words(char *sentence, char *words[])
{
    int count = 0;

    char *token = strtok(sentence, " ,;:-.!?");

    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " ,;:-.!?");
    }

    return count;
}

static void append_processed_word(char *word, char *new_sentence, int *pos)
{
    char first_symb = *word;

    new_sentence[(*pos)++] = first_symb;

    for (char *symb = word + 1; *symb != '\0'; symb++)
    {
        if (*symb != first_symb)
        {
            new_sentence[(*pos)++] = *symb;
        }
    }
}

static int has_next_valid_word(char *words[], int current_index, char *last_word)
{
    int has_next = 0;

    for (int k = current_index - 1; k >= 0 && !has_next; k--)
    {
        if (strcmp(words[k], last_word) != 0)
        {
            has_next = 1;
        }
    }

    return has_next;
}

void form_new_sentence(char *sentence, char *new_sentence)
{
    int pos = 0;

    char *words[MAX_SENTENCE_LENGTH];
    int count = split_to_words(sentence, words);

    char *last_word = words[count - 1];

    for (int j = count - 2; j >= 0; j--)
    {
        if (strcmp(words[j], last_word) != 0)
        {
            append_processed_word(words[j], new_sentence, &pos);

            if (has_next_valid_word(words, j, last_word))
            {
                new_sentence[pos++] = ' ';
            }
        }
    }

    new_sentence[pos] = '\0';
}
