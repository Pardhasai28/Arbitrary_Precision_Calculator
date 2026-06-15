#include "dll.h"

int create_list(char arr[], Dll **head, Dll **tail)
{
    int i = 0;                                      // Initialize index

    if(arr[i] == '+' || arr[i] == '-')              // Skip sign if present
    {
        i++;
    }

    while(arr[i] == '0')                            // Skip leading zeros
    {
        i++;
    }
    if(arr[i] == '\0')
    {
        Dll *new = malloc(sizeof(Dll));
        new->data = 0;
        new->prev = new->next = NULL;
        *head = *tail = new;
        return SUCCESS;
    }
    while(arr[i])                                   // Traverse remaining characters
    {
        Dll *new = (Dll *)malloc(1 * sizeof(Dll));  // Allocate new node
        if(new == NULL)
        {
            return FAILURE;                         // Return failure if malloc fails
        }

        new->data = (arr[i] - '0');                 // Convert char to integer digit
        new->prev = NULL;                           // Initialize prev pointer
        new->next = NULL;                           // Initialize next pointer
       
        if(*head == NULL)
        {
            *head = new;                            // First node becomes head
            *tail = new;                            // First node becomes tail
        }
        else
        {
            new->prev = *tail;                      // Link new node with tail
            (*tail)->next = new;
            *tail = new;                            // Update tail
        }

        i++;                                        // Move to next character
    }
    
    return SUCCESS;                                 // Return success
}