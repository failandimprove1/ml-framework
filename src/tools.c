#define MAX 50
#include <stdio.h>
#include <string.h>

void format_content_for_file(char content[])
{
    char suffix[29] = " ";
    strcat(content, suffix);
}

void write_to_file(char* path, char content[])
{
    FILE* fptr = fopen(path, "w+");
    format_content_for_file(content);
    fprintf(fptr, content);
    fclose(fptr);
}


FILE* read_file(char* path)
{
    return fopen(path, "r");
}