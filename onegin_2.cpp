#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int size_of_file(FILE *fp);
char *get_array(FILE *fp, int n);

int main( )
{
    FILE *fp = fopen("onegin.txt", "rb");
    if (fp == 0)
    {
        printf("Error while opening file.\n");
    }

    int n = size_of_file(fp);

    char *ptr = get_array(fp, n);

    for (int i = 0; i < n; i++)
    {
        putchar(ptr[i]);
    }
    return 0;
}

char *get_array(FILE *fp, int n)
{
    char *ptr = (char *) calloc(n, sizeof(char));
    if (ptr == NULL)
    {
        printf("Error while making array.\n");
        return 0;
    }

    size_t size_of_arr = fread(ptr, sizeof(char), n, fp);
    if (size_of_arr != (size_t) n)
    {
        printf("Error, the size of array isn't equal to the size of file.\n");
        return 0;
    }

    return ptr;
}


int size_of_file(FILE *fp)
{
    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return n;
}
