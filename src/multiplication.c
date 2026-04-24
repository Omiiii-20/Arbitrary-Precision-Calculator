
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    /* Step 1: Initialize variables */
    int carry, zero_count = 0;
    Dlist *t2 = *tail2;
    Dlist *finalH = NULL, *finalT = NULL;

    /* Step 2: Repeat for each digit in num2 (right to left) */
    while (t2)
    {
        Dlist *t1 = *tail1;
        Dlist *partH = NULL, *partT = NULL;
        carry = 0;

        /* Step 3: Multiply num1 with current digit of num2 */
        while (t1)
        {
            int product = (t1->data * t2->data) + carry;
            int digit = product % 10;
            carry = product / 10;

            /* Insert result at beginning of partial product */
            Dlist *new = (Dlist *)malloc(sizeof(Dlist));
            new->data = digit;
            new->prev = NULL;
            new->next = partH;
            if (partH) partH->prev = new;
            else partT = new;
            partH = new;

            t1 = t1->prev;
        }

        /* Step 4: If carry remains, insert it */
        if (carry)
        {
            Dlist *new = (Dlist *)malloc(sizeof(Dlist));
            new->data = carry;
            new->prev = NULL;
            new->next = partH;
            if (partH) partH->prev = new;
            else partT = new;
            partH = new;
        }

        /* Step 5: Add trailing zeros to partial product (based on position) */
        for (int i = 0; i < zero_count; i++)
        {
            Dlist *new = (Dlist *)malloc(sizeof(Dlist));
            new->data = 0;
            new->next = NULL;
            new->prev = partT;
            if (partT) partT->next = new;
            else partH = new;
            partT = new;
        }

        /* Step 6: Add partial product to final result */
        if (finalH == NULL)
        {
            finalH = partH;
            finalT = partT;
        }
        else
        {
            int sum_carry = 0;
            Dlist *tA = finalT;
            Dlist *tB = partT;
            Dlist *sumH = NULL, *sumT = NULL;

            while (tA || tB || sum_carry)
            {
                int val1 = (tA) ? tA->data : 0;
                int val2 = (tB) ? tB->data : 0;
                int sum = val1 + val2 + sum_carry;
                int digit = sum % 10;
                sum_carry = sum / 10;

                Dlist *new = (Dlist *)malloc(sizeof(Dlist));
                new->data = digit;
                new->prev = NULL;
                new->next = sumH;
                if (sumH) sumH->prev = new;
                else sumT = new;
                sumH = new;

                if (tA) tA = tA->prev;
                if (tB) tB = tB->prev;
            }

            /* Free old final list */
            free_list(&finalH, &finalT);
            free_list(&partH, &partT);

            finalH = sumH;
            finalT = sumT;
        }

        /* Step 7: Move to next digit of num2 */
        zero_count++;
        t2 = t2->prev;
    }

    /* Step 8: Remove leading zeros */
    while (finalH && finalH->data == 0 && finalH->next)
    {
        Dlist *del = finalH;
        finalH = finalH->next;
        finalH->prev = NULL;
        free(del);
    }

    /* Step 9: Set final result */
    *headR = finalH;
    *tailR = finalT;

    return SUCCESS;
}
