#ifndef PRINT
#define PRINT

void print_string(char *str);
void print_text(char **ptr_text, int lines_num);
void print_sort_text(char **ptr_text, int lines_num, int (*compare_func) (const char *, const char *));

#endif
