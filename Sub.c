#include "dll.h"

void Sub(Dll *head1, Dll *head2, Dll *tail1, Dll *tail2, Dll **rhead, Dll **rtail)
{
    int borrow = 0;                                  // Initialize borrow
    *rhead = NULL;   // initialize result head
    *rtail = NULL;   // initialize result tail
    while (tail1 != NULL || tail2 != NULL)            // Traverse both lists from end
    {
        int d1 = 0, d2 = 0;                          // Digits from both numbers

        if (tail1 != NULL)
        {
            d1 = tail1->data;                        // Get digit from list1
            tail1 = tail1->prev;                     // Move backward
        }

        if (tail2 != NULL)
        {
            d2 = tail2->data;                        // Get digit from list2
            tail2 = tail2->prev;                     // Move backward
        }

        int sub = d1 - borrow - d2;                  // Perform subtraction with borrow

        if (sub < 0)
        {
            sub += 10;                               // Adjust result if negative
            borrow = 1;                              // Set borrow for next iteration
        }
        else
        {
            borrow = 0;                              // Reset borrow
        }

        Dll *new = (Dll *)malloc(sizeof(Dll));       // Create new node
        new->data = sub;                             // Store result digit
        new->prev = NULL;
        new->next = NULL;

        if (*rhead == NULL)
        {
            *rhead = new;                            // First node becomes head
            *rtail = new;                            // First node becomes tail
        }
        else
        {
            new->next = *rhead;                      // Insert at front
            (*rhead)->prev = new;                    // Link previous head
            *rhead = new;                            // Update head
        }
    }

    while (*rhead && (*rhead)->data == 0 && (*rhead)->next != NULL)
    {
        Dll *temp = *rhead;                          // Temporary pointer to current head
        *rhead = (*rhead)->next;                     // Move head forward
        (*rhead)->prev = NULL;                       // Set new head prev to NULL
        free(temp);                                  // Free removed node (leading zero)
    }
}