#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

int size_of_file(FILE *fp);
int num_of_lines(char *text, int n);
char *get_array(FILE *fp, int n);
char **point_array(char *text, int n, int k);
void sort_strings(char **ptr_text, int k);
int compare_letters(char par1, char par2);
size_t str_len(const char *s);
int min(int a, int b);
char *make_letters(char *par1);
int compare_strings(char *par1, char *par2);
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

    print_text(ptr_text, k);
    putchar('\n');

    printf("1\n");

    sort_strings(ptr_text, k);

    printf("1\n");

    print_text(ptr_text, k);

    printf("1\n");

    free (ptr_text);
    free (text);
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

int compare_letters(char par1, char par2)
{
    if (par1 > par2)
    {
        return 1;
    }
    return 0;
}

size_t str_len(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        {
            i++;
        }
    return i;
}

int min(int a, int b)
{
    if (a > b) return b;
    else return a;
}

char *make_letters(char *par1)
{
    int len = (int) str_len(par1);
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(par1[i]))
        {
            k++;
        }
    }
    char s1[k];
    int q = 0;
    for (int j = 0; j < len; j++)
    {
        s1[q] = toupper(par1[j]);
        q++;
    }
    return (char *) s1;
}

int compare_strings(char *par1, char *par2)
{
    char *s1 = make_letters(par1);
    char *s2 = make_letters(par2);

    int len1 = (int) str_len(s1);
    int len2 = (int) str_len(s2);
    int len = min(len1, len2);

    int i = 0;
    int k = 0;
    do
    {
        k++;
        i++;
    } while (compare_letters(s1[i], s2[i]) && i < len);
    if (k == len - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sort_strings(char **ptr_text, int k)
{
    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i < k - j; i++)
        {
            if (compare_strings(ptr_text[i], ptr_text[i+1]))
            {
                char *temp = ptr_text[i];
                ptr_text[i] = ptr_text[i + 1];
                ptr_text[i + 1] = temp;
            }
        }
    }
}

char **point_array(char *text, int n, int k)
{
    char **ptr_text = (char **) calloc(k, sizeof(char *));
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

    if (ptr_text == NULL)
    {
        printf("Error while making pointer to the array.\n");
        return 0;
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
    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return n;
}
