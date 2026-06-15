#include "dll.h"

// Remove leading zeros
void remove_leading_zeros(Dll **head, Dll **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next != NULL) // skip leading zeros except last node
    {
        Dll *temp = *head;                     // store current head
        *head = (*head)->next;                 // move head forward
        (*head)->prev = NULL;                 // update prev of new head
        free(temp);                            // free removed node
    }

    // update tail
    Dll *t = *head;                            // start from head
    while (t && t->next)                       // go till last node
        t = t->next;
    *tail = t;                                 // update tail pointer
}

// Long Division
void Div(Dll *head1, Dll *head2, Dll *tail1, Dll *tail2,Dll **rhead, Dll **rtail)
{
    Dll *temphead = NULL, *temptail = NULL;   // partial dividend
    Dll *qhead = NULL, *qtail = NULL;         // quotient list
    Dll *rhead1 = NULL, *rtail1 = NULL;       // remainder list

    Dll *cur = head1;                         // pointer to traverse dividend

    while (cur != NULL)                       // process each digit
    {
        // Bring down digit
        Dll *newnode = malloc(sizeof(Dll));   // create new node
        newnode->data = cur->data;            // copy digit
        newnode->next = NULL;
        newnode->prev = NULL;

        if (temphead == NULL)                 // if temp list empty
            temphead = temptail = newnode;    // initialize it
        else
        {
            newnode->prev = temptail;         // link new node
            temptail->next = newnode;
            temptail = newnode;               // update tail
        }

        // remove leading zeros before compare
        remove_leading_zeros(&temphead, &temptail); // clean temp list

        //  Find how many times divisor fits
        int count = 0;                        // quotient digit counter

        while (compare_list(temphead, head2) >= 0) // while temp >= divisor
        {
            Sub(temphead, head2, temptail, tail2, &rhead1, &rtail1); // subtract divisor

            // free old temp
            while (temphead != NULL)          // delete old temp list
            {
                Dll *del = temphead;
                temphead = temphead->next;
                free(del);
            }

            temphead = rhead1;                // update temp with remainder
            temptail = rtail1;

            rhead1 = rtail1 = NULL;           // reset remainder pointers

            // remove leading zeros after subtraction
            remove_leading_zeros(&temphead, &temptail); // clean again

            count++;                          // increment quotient digit
        }

        // Add quotient digit (skip leading zero)
        if (!(qhead == NULL && count == 0))   // avoid leading zero in quotient
        {
            Dll *qnode = malloc(sizeof(Dll)); // create quotient node
            qnode->data = count;              // store count
            qnode->next = NULL;
            qnode->prev = NULL;

            if (qhead == NULL)                // if first node
                qhead = qtail = qnode;
            else
            {
                qnode->prev = qtail;          // link node
                qtail->next = qnode;
                qtail = qnode;               // update tail
            }
        }

        cur = cur->next;                      // move to next digit
    }

    // If quotient is empty → result is 0
    if (qhead == NULL)
    {
        Dll *node = malloc(sizeof(Dll));      // create node
        node->data = 0;                       // store 0
        node->next = node->prev = NULL;
        qhead = qtail = node;                 // assign as quotient
    }

    *rhead = qhead;                           // return quotient head
    *rtail = qtail;                           // return quotient tail

    // free remaining temp list
    while (temphead != NULL)                  // delete temp list
    {
        Dll *del = temphead;
        temphead = temphead->next;
        free(del);
    }
}