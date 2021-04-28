#pragma once
#include <stdlib.h>

// NOTE: Free buffer when done with it.
char* read_entire_file(char* file)
{
    FILE* source_file = fopen(file, "rb");
    if (!source_file)
    {
        perror("read_entire_file: ");
        return 0; // Will cause segfault. 
    }
    fseek(source_file, 0, SEEK_END);
    long src_size = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);
    char* buffer = malloc(src_size + 1);
    fread(buffer, 1, src_size, source_file);
    fclose(source_file);
    buffer[src_size] = 0;
    return buffer;
}
