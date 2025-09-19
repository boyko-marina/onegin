#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char *get_arr(FILE *fp, int n);
int size_file (FILE *fp);

int main()
{
    FILE *fp = fopen("emoboy.txt", "r");
    if (fp == 0) {
        printf("Error in opening file");
        return 0;
    }
    int n = size_file (fp);
    printf("%d\n", n);
    char *ptr = get_arr(fp, n);
    int i;
    for (i = 0; i < n; i++) {
        putchar(ptr[i]);
    }
    int a[10000]=[];
    for (i = 0; i < n; i++) {
        if (ptr[i] == '\0') {

        }
    }


    free (ptr);
}

char *get_arr(FILE *fp, int n) {
    char *ptr = (char*) calloc(n, sizeof(char));
    if ( (char*) calloc(n, sizeof(char)) == NULL) {
        printf("Error in creating array\n");
        return 0;
    }

    size_t read_size =  fread(ptr, sizeof(char), n, fp);
    if (read_size != (size_t) n) {
        printf("Array sizes aren't equal\n");
        return 0;
    }
    return ptr;
}

int size_file (FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return n;
}
