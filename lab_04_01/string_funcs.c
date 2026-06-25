#include <stdio.h>
#include "string_funcs.h"

size_t my_strcspn(const char *str1, const char *str2)
{
    int length = 0;
    int found = 0;

    for (int i = 0; str1[i] != '\0' && !found; i++)
    {
        for (int j = 0; str2[j] != '\0' && !found; j++)
        {
            if (str1[i] == str2[j])
                found = 1;
        }

        if (!found)
            length++;
    }

    return length;
}

size_t my_strspn(const char *str1, const char *str2)
{
    int length = 0;
    int stop = 0;

    for (int i = 0; str1[i] != '\0' && !stop; i++)
    {
        int found = 0;

        for (int j = 0; str2[j] != '\0' && !found; j++)
        {
            if (str1[i] == str2[j])
                found = 1;
        }

        if (found)
            length++;
        else
            stop = 1;
    }

    return length;
}

const char *my_strpbrk(const char *s, const char *accept)
{
    const char *pt = NULL;

    for (; *s != '\0' && pt == NULL; s++)
    {
        const char *temp = accept;

        for (; *temp != '\0' && pt == NULL; temp++)
        {
            if (*s == *temp)
                pt = s;
        }
    }

    return pt;
}

const char *my_strchr(const char *str, int ch)
{
    const char *pt = NULL;
    int done = 0;

    for (int i = 0; !done; i++)
    {
        if (str[i] == (char)ch && pt == NULL)
            pt = str + i;

        if (str[i] == '\0')
            done = 1;
    }

    return pt;
}

const char *my_strrchr(const char *str, int ch)
{
    const char *pt = NULL;
    int done = 0;

    for (int i = 0; !done; i++)
    {
        if (str[i] == (char)ch)
            pt = str + i;

        if (str[i] == '\0')
            done = 1;
    }

    return pt;
}
