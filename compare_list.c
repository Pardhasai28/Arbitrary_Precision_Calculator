#include "dll.h"

int compare_list(Dll *h1, Dll *h2)
{
    int len1 = 0, len2 = 0;                 // Initialize lengths of both lists
    Dll *t1 = h1, *t2 = h2;                 // Temporary pointers for traversal

    while(t1)
    { 
        len1++;                            // Count nodes in first list
        t1 = t1->next;                     // Move to next node
    }

    while(t2)
    {
        len2++;                            // Count nodes in second list
        t2 = t2->next;                     // Move to next node
    }

    if(len1 > len2) 
        return 1;                          // First number is larger (more digits)

    if(len1 < len2) 
        return -1;                         // Second number is larger (more digits)

    while(h1 && h2)
    {
        if(h1->data > h2->data) 
            return 1;                      // First list has larger digit at this position

        if(h1->data < h2->data) 
            return -1;                     // Second list has larger digit at this position

        h1 = h1->next;                     // Move to next node in first list
        h2 = h2->next;                     // Move to next node in second list
    }

    return 0;                              // Both lists represent equal numbers
}