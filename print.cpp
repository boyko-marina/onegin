#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "print.h"
#include "sort_strings.h"

void print_string(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
}

void print_text(char **ptr_text, int lines_num)
{
    for (int i = 0; i < lines_num; i++)
    {
        print_string(ptr_text[i]);
    }
}

void print_sort_text(char **ptr_text, int lines_num, int (*compare_func) (const char *, const char *))
{
    sort_strings(ptr_text, lines_num, compare_func);
    print_text(ptr_text, lines_num);
    putchar('\n');
}
