#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "sort_strings.h"
#include "compare_strings.h"

int str_len(const char *s)
{
    int i = 0;
    while (s[i] != '\n')
        {
            i++;
        }
    return i;
}

int compare_strings_from_start(const char *par1, const char *par2)
{
    int len1 = str_len(par1);
    int len2 = str_len(par2);
    int i1 = 0;
    int i2 = 0;

    for (; i1 <= len1 && i2 <= len2; i1++, i2++)
    {
        while (i1 < len1 && !isalpha(par1[i1])) i1++;
        while (i2 < len2 && !isalpha(par2[i2])) i2++;

        if ((i1 == len1) && (i2 == len2))
        {
            return 0;
        }

        if ((i1 == len1) && (i2 != len2))
        {
            return -1;
        }

        if ((i1 != len1) && (i2 == len2))
        {
            return 1;
        }

        char c1 = toupper(par1[i1]);
        char c2 = toupper(par2[i2]);

        if (c1 > c2)
        {
            return 1;
        }
        if (c1 < c2)
        {
            return -1;
        }
    }

    return 0;
}

int compare_strings_from_end(const char *par1, const char *par2)
{
    int i1 = str_len(par1) - 1;
    int i2 = str_len(par2) - 1;

    for (; i1 >= -1 && i2 >= -1; i1--, i2--)
    {
        while (i1 >= 0 && !isalpha(par1[i1])) i1--;
        while (i2 >= 0 && !isalpha(par2[i2])) i2--;

        if (i1 < 0 && i2 < 0)
        {
            return 0;
        }

        if (i1 < 0 && i2 >= 0)
        {
            return -1;
        }

        if (i1 >= 0 && i2 < 0)
        {
            return 1;
        }

        char c1 = toupper(par1[i1]);
        char c2 = toupper(par2[i2]);

        if (c1 > c2)
        {
            return 1;
        }
        if (c1 < c2)
        {
            return -1;
        }
    }

    return 0;
}
