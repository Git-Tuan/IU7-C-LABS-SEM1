#include "status.h"
#include "string_funcs.h"
#include "string_io.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 258
#define MAX_WORD_LENGTH 16
#define MAX_NUM_OF_WORDS 128

int main(void)
{
    return_code_t rc = STATUS_SUCCESS;
    char date[MAX_SENTENCE_LENGTH];
    char date_matr[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH];
    int count = 0;
    int found_valid = 0;

    rc = input_string(date);

    if (rc == STATUS_SUCCESS)
    {
        split_words(date, date_matr, &count);

        if (count == 3)
        {
            int is_leap = 0;
            int month = 0;
            int year_ok = 0;
            int month_ok = 0;
            int day_ok = 0;

            year_ok = (check_year(date_matr[2], &is_leap) == STATUS_SUCCESS);

            if (year_ok)
                month = check_month(date_matr[1], strlen(date_matr[1]));

            month_ok = (year_ok && month != 0);

            if (month_ok)
                day_ok = (check_day(date_matr[0], month, is_leap) == STATUS_SUCCESS);

            if (year_ok && month_ok && day_ok)
                found_valid = 1;
        }
    }

    if (rc == STATUS_SUCCESS && found_valid)
        printf("YES");
    else if (rc == STATUS_SUCCESS && found_valid == 0)
        printf("NO");

    return rc;
}
