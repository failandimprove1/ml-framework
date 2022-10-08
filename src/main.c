#include <stdio.h>
#include <string.h>
#include "tools.h"

int main()
{
    char main_buffer [MAX];
    write_to_file("layerdata", "hejsan 123");
    FILE* text = read_file("layerdata");
    //read_file("data");
    
    while (fgets(main_buffer, MAX, text))
    {
        printf(main_buffer);
        printf("\n");
    }
    //fclose(fptr);
    return 0;
}
