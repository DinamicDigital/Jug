/*
 *  The purpose of the preprocessor is to remove anything that isnt relevant data to the actual parsing.
 *  Note the "preprocessor" here is not like the C one, there are no macros.
 *  
 *
 *  Example:
 *  We remove comments, spaces, and newlines (as we are using semi-colons to mark end of statements.
 *  
 */

#include "preprocess.h"
#include <stdio.h>
#include "util.h"
#include "jug_types.h"
#include "types.h"
#include <string.h>

typedef struct _S_Preprocess_Data
{
    bool comment;
} Preprocess_Data;

String preprocess(char* path)
{	
    Preprocess_Data data;

    char* file = read_entire_file(path);
    size_t file_size = strlen(file);
    
    
    String string = { .str = calloc(file_size, sizeof(char)), .size = 0 };
        // TODO: Is memory cheap enough to just put in the file size directly? The size will almost certainly shrink atleast a little after preprocessing. We may want to resize this later.
    int si = 0; // new_str iterator
    
    for (int i = 0; file[i] != 0; i++)
    {   
        char c = file[i];
        switch (c)
        {
        case '#':
            {
                data.comment = true;
            } break;
        case '\n':
            {
                if (data.comment == true)
                    data.comment = false;
            } break;
        case ' ':
            {
                continue;
            } break;
        default:
            {
                if (data.comment == true)
                    continue;

                string.str[si] = c;
                si++;
            }    
        }
    }
    free(file);
    return string;
}

