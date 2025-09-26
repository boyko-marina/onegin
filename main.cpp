#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "print.h"
#include "make_arr_and_ptr_arr.h"
#include "sort_strings.h"
#include "compare_strings.h"

#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int main( )
{
    FILE *fp = fopen("onegin.txt", "rb");
    if (fp == 0)
    {
        printf("Error while opening file.\n");
    }

    int file_size = size_of_file(fp);
    char *text = make_array(fp, file_size);

    int lines_num = num_of_lines(text, file_size);
    char **ptr_text = point_array(text, file_size, lines_num);
//    printf("values n=%d, k=%d\n", n, k);

    printf(COLOR_CYAN "Original text.\n" COLOR_RESET);
    print_text(ptr_text, lines_num);
    putchar('\n');

    printf(COLOR_CYAN "Sorted text by start.\n" COLOR_RESET);
    print_sort_text(ptr_text, lines_num, compare_strings_from_start);

    printf(COLOR_CYAN "Sorted text by end.\n" COLOR_RESET);
    print_sort_text(ptr_text, lines_num, compare_strings_from_end);

//    printf("end of program\n");

    free (ptr_text);
    free (text);
    fclose(fp);
}
