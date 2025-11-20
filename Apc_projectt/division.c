// Name : Om Bidikar
// Date : 14nd Nov 2025
//Batch : 25017_172


    #include "apc.h"
    void increment_list(Dlist **head, Dlist **tail);
    int compare_lists(Dlist *head1, Dlist *head2);


    int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
    {
        /* ---------- Step 1: Handle Division by Zero ---------- */
        if (*head2 == NULL)
        {
            printf("Error: Division by zero is not allowed.\n");
            return FAILURE;
        }

        /* ---------- Step 2: Handle Dividend = 0 ---------- */
        if (*head1 == NULL)
        {
            insert_at_last(headR, tailR, 0);
            return SUCCESS;
        }

        /* ---------- Step 3: Create a Temporary Copy of Operand1 ---------- */
        Dlist *tempH = NULL, *tempT = NULL;
        Dlist *quotH = NULL, *quotT = NULL;

        Dlist *curr = *head1;
        while (curr)
        {
            insert_at_last(&tempH, &tempT, curr->data);
            curr = curr->next;
        }

        /* Initialize quotient list with 0 */
        insert_at_last(&quotH, &quotT, 0);

        /* ---------- Step 4: Perform Repeated Subtraction ---------- */
        while (compare_lists(tempH, *head2) >= 0)
        {
            Dlist *subH = NULL, *subT = NULL;

            /* Perform subtraction using existing subtraction() */
            subtraction(&tempH, &tempT, head2, tail2, &subH, &subT);

            /* Free old temp and copy new remainder */
            free_list(&tempH, &tempT);

            Dlist *node = subH;
            while (node)
            {
                insert_at_last(&tempH, &tempT, node->data);
                node = node->next;
            }

            /* Increment quotient by +1 */
            increment_list(&quotH, &quotT);

            /* Free temporary subtraction result */
            free_list(&subH, &subT);
        }

        /* ---------- Step 5: Copy Quotient to Result ---------- */
        Dlist *q = quotH;
        while (q)
        {
            insert_at_last(headR, tailR, q->data);
            q = q->next;
        }

        /* ---------- Step 6: Cleanup ---------- */
        free_list(&tempH, &tempT);
        free_list(&quotH, &quotT);

        return SUCCESS;
    }

    /* Compare two linked lists numerically */
    /* compare_lists removed (defined in list_utils.c) */

    /* Increment a number (represented as a linked list) by +1 */
    void increment_list(Dlist **head, Dlist **tail)
    {
        Dlist *temp = *tail;
        int carry = 1;

        while (temp && carry)
        {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            temp = temp->prev;
        }

        if (carry)
        {
            Dlist *new = malloc(sizeof(Dlist));
            new->data = carry;
            new->prev = NULL;
            new->next = *head;
            if (*head)
                (*head)->prev = new;
            *head = new;
        }
    }

    /* Free the memory of a doubly linked list */
    /* free_list removed (defined in list_utils.c) */
