#include <stdio.h>
#include "types.h"
#include "preprocess.h"

int main()
{
    
	
    String s = preprocess("config.jug");
    
    printf("%s\n", s.str);

    return 0;
}

