#include "string_funcs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

return_code_t check_day(const char *day, int month, int is_leap)
{
    return_code_t status = STATUS_SUCCESS;
    const int max_day_value = 31;
    const int min_day_value = 1;

    for (size_t i = 0; day[i] != '\0' && status == STATUS_SUCCESS; i++)
    {
        if (!isdigit((unsigned char)day[i]))
            status = STATUS_INPUT_ERROR;
    }

    if (status == STATUS_SUCCESS)
    {
        long day_val = atol(day);

        if (day_val < min_day_value || day_val > max_day_value)
        {
            status = STATUS_DAY_ERROR;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day_val > max_day_value - 1)
        {
            status = STATUS_DAY_ERROR;
        }
        else if (month == 2)
        {
            if (is_leap && day_val > max_day_value - 2)
                status = STATUS_DAY_ERROR;
            else if (!is_leap && day_val > max_day_value - 3)
                status = STATUS_DAY_ERROR;
        }
    }

    return status;
}

int check_month(char *month, int length)
{
    int res = 0;

    const char *months[] = 
    {
        "january", "february", "march",     "april",   "may",      "june",
        "july",    "august",   "september", "october", "november", "december"
    };

    for (int i = 0; i < length; i++)
        month[i] = tolower(month[i]);

    const int num_of_months = 12;

    for (int j = 0; j < num_of_months && res == 0; j++)
    {
        if (strcmp(month, months[j]) == 0)
            res = j + 1;
    }

    return res;
}

return_code_t check_year(const char *year, int *is_leap)
{
    return_code_t rc = STATUS_SUCCESS;
    const int max_year_value = 9999;
    long integer_val = 0;

    for (size_t i = 0; year[i] != '\0' && rc == STATUS_SUCCESS; i++)
        if (!isdigit((unsigned char)year[i]))
            rc = STATUS_INPUT_ERROR;

    if (rc == STATUS_SUCCESS)
    {
        integer_val = atol(year);
        if (integer_val > max_year_value)
            rc = STATUS_YEAR_ERROR;
    }
    if (rc == STATUS_SUCCESS)
        *is_leap = ((integer_val % 4 == 0 && integer_val % 100 != 0) || (integer_val % 400 == 0));

    return rc;
}

static int is_delim(char c)
{
    return (c == '\t') || (c == ' ') || (c == '\n');
}

void split_words(const char *sentence, char words[][MAX_WORD_LENGTH], int *count)
{
    int i = 0;
    int letter_index = 0;
    int inside_word = 0;

    while (sentence[i] != '\0')
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

        i++;
    }
    if (inside_word)
    {
        words[*count][letter_index] = '\0';
        (*count)++;
    }
}
