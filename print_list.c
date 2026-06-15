#include "dll.h"

int print_list(Dll *head)
{   
    if(head == NULL)
        return FAILURE;                 // Return failure if list is empty
    
    while(head != NULL)
    {
        printf(YELLOW"%d"RESET, head->data);      // Print data of current node
        head = head->next;             // Move to next node
    }

    printf("\n");                      // Print newline after entire list
    return SUCCESS;
}
int print_resultlist(Dll *head)
{   
    if(head == NULL)
        return FAILURE;                 // Return failure if list is empty
    
    while(head != NULL)
    {
        printf(RED"%d"RESET, head->data);      // Print data of current node
        head = head->next;             // Move to next node
    }

    printf("\n");                      // Print newline after entire list
    return SUCCESS;
}