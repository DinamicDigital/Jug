#include <stdio.h>
#include "util.h"
#include "types.h"
#include <string.h>


typedef struct Parse_Data
{
    bool comment;
} Parse_Data;

int main()
{
    Parse_Data data = { 0 };
	
    char* file = read_entire_file("config.jug");
    
    char token[1024] = { 0 };
    
    int j = 0; 
    for (int i = 0; file[i] != 0; i++)
    {   
        char c = file[i];
        //printf("%c, %d\n", file[j], j); 
        if (c == '#')
        {
            data.comment = true;
        }
        else if (c == '\n')
        {
            //printf("\\n found\n");
            if (data.comment == true)
            {
                j = 0;
                data.comment = false;
            }
        }
        else
        {
            if (data.comment == true)
                continue;

            token[j] = c;
            //printf(" %c\n", c);
            printf("%s\n", token);
            j++;
        }
    } 
    return 0;
}

