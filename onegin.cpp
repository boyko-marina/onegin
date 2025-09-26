#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int size_of_file(FILE *fp);
int num_of_lines(char *text, int n);
char *get_array(FILE *fp, int n);
char **point_array(char *text, int n, int k);
void sort_strings(char **ptr_text, int k, int (*compare_func) (const char *, const char *));
int str_len(const char *s);
int compare_strings_from_start(const char *par1, const char *par2);
int compare_strings_from_end(const char *par1, const char *par2);
void print_string(char *str);
void print_text(char **ptr_text, int k);

int main( )
{
    FILE *fp = fopen("onegin.txt", "rb");
    if (fp == 0)
    {
        printf("Error while opening file.\n");
    }

    int n = size_of_file(fp);
    char *text = get_array(fp, n);

    int k = num_of_lines(text, n);
    char **ptr_text = point_array(text, n, k);
//    printf("values n=%d, k=%d\n", n, k);

    printf(COLOR_CYAN "Original text.\n" COLOR_RESET);
    print_text(ptr_text, k);
    putchar('\n');

    printf(COLOR_CYAN "Sorted text by start.\n" COLOR_RESET);
    sort_strings(ptr_text, k, compare_strings_from_start);
    print_text(ptr_text, k);
    putchar('\n');

    printf(COLOR_CYAN "Sorted text by end.\n" COLOR_RESET);
    sort_strings(ptr_text, k, compare_strings_from_end);
    print_text(ptr_text, k);
    putchar('\n');


//    printf("end of program\n");

    free (ptr_text);
    free (text);
    fclose(fp);
}

void print_string(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
}

void print_text(char **ptr_text, int k)
{
    for (int i = 0; i < k; i++)
    {
        print_string(ptr_text[i]);
    }
}

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

void sort_strings(char **ptr_text, int k, int (*compare_func) (const char *, const char *))
{
    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i < k - j; i++)
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

char **point_array(char *text, int n, int k)
{
    char **ptr_text = (char **) calloc(k, sizeof(char *));

    if (ptr_text == NULL)
    {
        printf("Error while making pointer to the array.\n");
        return 0;
    }

    ptr_text[0] = &text[0];
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (text[i] == '\n')
        {
            j++;
            if (j < k)
            {
                ptr_text[j] = &text[i+1];
            }
            else
            {
                printf("The number of lines is bigger than numbers of pointer.");
                break;
            }
        }
    }

    return ptr_text;
}

char *get_array(FILE *fp, int n)
{
    char *text = (char *) calloc(n, sizeof(char));
    if (text == NULL)
    {
        printf("Error while making array.\n");
        return 0;
    }

    size_t size_of_arr = fread(text, sizeof(char), n, fp);

    if (size_of_arr != (size_t) n)
    {
        printf("Error, the size of array isn't equal to the size of file.\n");
        return 0;
    }

    return text;
}

int num_of_lines(char *text, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '\n')
        {
            k++;
        }
    }

    return k;
}

int size_of_file(FILE *fp)
{
    long pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, pos, SEEK_SET);
    return n;
}

// int size_of_file(FILE *fp)
// {
//     fseek(fp, 0L, SEEK_END);
//     int n = ftell(fp);
//     fseek(fp, 0L, SEEK_SET);
//     return n;
// }
