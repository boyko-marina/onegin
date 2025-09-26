#ifndef MAKE_ARR_AND_PTR_ARR
#define MAKE_ARR_AND_PTR_ARR

int size_of_file(FILE *fp);
char *make_array(FILE *fp, int file_size);
int num_of_lines(char *text, int file_size);
char **point_array(char *text, int file_size, int lines_num);

#endif
