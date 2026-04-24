// Name : Om Bidikar
// Date : 14nd Nov 2025
//Batch : 25017_172


#include "apc.h"

/* Helper function to insert a digit at the beginning (for result storage) */
void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    if (!new)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

/* Function to perform addition of two big numbers stored in linked lists */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0, sum;

    /* Start from the least significant digits (end of the lists) */
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    /* Loop until both lists are exhausted */
    while (temp1 != NULL || temp2 != NULL)
    {
        int val1 = (temp1) ? temp1->data : 0;
        int val2 = (temp2) ? temp2->data : 0;

        sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        insert_at_first(headR, tailR, sum);

        if (temp1)
            temp1 = temp1->prev;
        if (temp2)
            temp2 = temp2->prev;
    }

    /* If carry remains, insert it */
    if (carry)
        insert_at_first(headR, tailR, carry);

    return SUCCESS;
}
