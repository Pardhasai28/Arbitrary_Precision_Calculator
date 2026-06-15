#include "dll.h"

int validate_num(char argv[])
{   
    int i = 0;                                      // Initialize index

    if(argv[i] == '+' || argv[i] == '-')            // Check for optional sign
        i++;

    while(argv[i])                                  // Traverse entire string
    {   
        if(isdigit(argv[i]))                        // Check if current char is digit
            i++;
        else 
            return 0;                               // Invalid character found
    }

    return 1;                                       // Valid number
}

int validate_operator(char argv[])
{
    if(strlen(argv) != 1)                           // Operator must be single character
        return 0;

    if(argv[0] == '+' || argv[0] == '-' || argv[0] == 'x' || 
       argv[0] == '/') // Check valid operators
        return 1;
    else
        return 0;                                   // Invalid operator
}