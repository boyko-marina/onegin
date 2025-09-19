#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int size_of_file(FILE *fp);
int num_of_lines(char *text, int n);
char *get_array(FILE *fp, int n);
char **point_array(char *text, int n, int k);

int main( )
{
    FILE *fp = fopen("onegin.txt", "rb");
    if (fp == 0)
    {
        printf("Error while opening file.\n");
    }

    int n = size_of_file(fp);
    char *text = get_array(fp, n);

    for (int i = 0; i < n; i++)
    {
        putchar(text[i]);
    }

    int k = num_of_lines(text, n);
    char **ptr_text = point_array(text, n, k);

/*    for (int q = 0; q < k; q++)
    {
        putchar(*ptr_text[q]);
//        printf("%p\n", ptr_text[q]);
    }
*/
    free (ptr_text);
    free (text);
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
