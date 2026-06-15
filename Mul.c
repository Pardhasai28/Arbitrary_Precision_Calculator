#include "dll.h"

void Mul(Dll *head1, Dll *head2, Dll *tail1, Dll *tail2, Dll **rhead, Dll **rtail)
{
    int shift = 0;                                      // Keeps track of position (like multiplying by 10^shift)

    *rhead = NULL;                                      // Initialize result head
    *rtail = NULL;                                      // Initialize result tail

    while(tail2 != NULL)                                // Traverse second number from least significant digit
    {
        Dll *temp = tail1;                              // Pointer to traverse first number
        int carry = 0;                                  // Initialize carry

        Dll *temphead = NULL, *temptail = NULL;         // Temporary list for partial product

        while(temp != NULL)                             // Multiply each digit of first number
        {
            int sum = (temp->data * tail2->data) + carry; // Multiply digits + carry
            int mul = sum % 10;                         // Extract last digit
            carry = sum / 10;                           // Update carry

            Dll *new = malloc(sizeof(Dll));             // Create new node
            new->data = mul;                            // Store digit
            new->prev = NULL;
            new->next = NULL;

            if(temphead == NULL)
            {
                temphead = temptail = new;              // First node in temp list
            }
            else
            {
                new->next = temphead;                   // Insert at front
                temphead->prev = new;
                temphead = new;
            }

            temp = temp->prev;                          // Move backward in first number
        }

        if(carry > 0)                                   // If carry remains
        {
            Dll *new = malloc(sizeof(Dll));
            new->data = carry;
            new->prev = NULL;
            new->next = temphead;                       // Add carry at front

            if(temphead)
                temphead->prev = new;

            temphead = new;

            if(temptail == NULL)
                temptail = new;
        }

        for(int i = 0; i < shift; i++)                  // Add trailing zeros based on position
        {
            Dll *new = malloc(sizeof(Dll));
            new->data = 0;
            new->next = NULL;
            new->prev = temptail;

            if(temptail)
                temptail->next = new;
            else
                temphead = new;

            temptail = new;
        }
        
        if(*rhead == NULL)
        {
            *rhead = temphead;                          // First partial result becomes final result
            *rtail = temptail;
        }
        else
        {
            Dll *reshead = NULL, *restail = NULL;      // Temporary result for addition

            Add(*rhead, temphead, *rtail, temptail, &reshead, &restail); // Add partial product

            while(*rhead)                              // Free old result list
            {
                Dll *del = *rhead;
                *rhead = (*rhead)->next;
                free(del);
            }
            *rtail = NULL;

            *rhead = reshead;                          // Update result
            *rtail = restail;

            while(temphead)                            // Free temporary list
            {
                Dll *del = temphead;
                temphead = temphead->next;
                free(del);
            }
            temptail = NULL;
        }

        shift++;                                       // Increase shift (next digit position)
        tail2 = tail2->prev;                           // Move to next digit of second number
    }
}