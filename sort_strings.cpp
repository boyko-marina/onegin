//! @file
#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "sort_strings.h"

void sort_strings(char **ptr_text, int lines_num, int (*compare_func) (const char *, const char *))
{
    for (int j = 1; j < lines_num; j++)
    {
        for (int i = 0; i < lines_num - j; i++)
        {
            if (compare_func(ptr_text[i], ptr_text[i+1]) == 1)
            {
                // printf("before str1: \n");
                // print_string(ptr_text[i]);
                // printf("before str2: \n");
                // print_string(ptr_text[i+1]);

                char *temp = ptr_text[i];
                ptr_text[i] = ptr_text[i + 1];
                ptr_text[i + 1] = temp;

                // printf("after str1: \n");
                // print_string(ptr_text[i]);
                // printf("after str2: \n");
                // print_string(ptr_text[i+1]);

                // printf("\n");
            }
        }
    }
}
