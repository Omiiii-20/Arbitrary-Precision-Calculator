
#include "apc.h"

/* Function to perform subtraction of two big numbers stored in linked lists */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0, diff;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int cmp = compare_lists(*head1, *head2);

    if (cmp == 0)
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    int negative = 0;

    /* Ensure we always subtract smaller from larger */
    if (cmp < 0)
    {
        Dlist *tmpH = *head1, *tmpT = *tail1;
        *head1 = *head2;
        *tail1 = *tail2;
        *head2 = tmpH;
        *tail2 = tmpT;

        negative = 1;
        temp1 = *tail1;
        temp2 = *tail2;
    }

    while (temp1 || temp2)
    {
        int val1 = (temp1) ? temp1->data : 0;
        int val2 = (temp2) ? temp2->data : 0;

        val1 = val1 - borrow;

        if (val1 < val2)
        {
            val1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        diff = val1 - val2;

        insert_at_first(headR, tailR, diff);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    /* Remove leading zeros */
    while ((*headR) && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }
printf("Result (Subtraction): ");
    /* Print sign if result is negative */
    if (negative)
     {
        
        printf("-");
     }
    return SUCCESS;
}
