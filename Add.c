#include "dll.h"

void Add(Dll *head1, Dll *head2, Dll *tail1, Dll *tail2, Dll **rhead, Dll **rtail)
{
    int carry = 0, sum;                           // Initialize carry and sum
    *rhead = NULL;                                // Result head
    *rtail = NULL;                                // Result tail

    while(tail1 != NULL || tail2 != NULL)          // Run until both lists end
    {
        int val1 = 0, val2 = 0;                   // Store digits safely

        if(tail1 != NULL)
        {
            val1 = tail1->data;                   // Take value from list1
            tail1 = tail1->prev;                  // Move backward
        }

        if(tail2 != NULL)
        {
            val2 = tail2->data;                   // Take value from list2
            tail2 = tail2->prev;                  // Move backward
        }

        sum = val1 + val2 + carry;                // Add digits + carry
        carry = sum / 10;                         // Update carry
        int digit = sum % 10;                     // Extract single digit

        Dll *new = (Dll *)malloc(sizeof(Dll));    // Create new node
        new->data = digit;                        // Store digit
        new->prev = NULL;
        new->next = NULL;

        if(*rhead == NULL)
        {
            *rhead = new;                         // First node
            *rtail = new;
        }
        else
        {
            new->next = *rhead;                   // Insert at front
            (*rhead)->prev = new;
            *rhead = new;
        }
    }

    if(carry)                                     // If carry remains
    {
        Dll *new = (Dll *)malloc(sizeof(Dll));
        new->data = carry;
        new->prev = NULL;
        new->next = NULL;

        new->next = *rhead;
        if(*rhead)
            (*rhead)->prev = new;
        *rhead = new;

        if(*rtail == NULL)
            *rtail = new;
    }
}