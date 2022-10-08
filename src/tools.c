#define MAX 50
#include <stdio.h>
#include <string.h>

void format_content_for_file(char* content)
{
        strcat(content, " ");
}

void write_to_file(char* path, char* content)
{
    FILE* fptr = fopen(path, "a");
    printf(content);
    fprintf(fptr, content);
    fclose(fptr);
}


FILE* read_file(char* path)
{
    return fopen(path, "r");
}