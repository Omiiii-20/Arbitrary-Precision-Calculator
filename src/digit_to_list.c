

#include "apc.h"
#include <stdlib.h>
#include <stdio.h>


/* Helper function to insert a digit at the end of a doubly linked list */
/* insert_at_last removed (defined in list_utils.c) */

/* Function to convert operands (argv[1] & argv[3]) into linked lists */
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    char *num1 = argv[1];
    char *num2 = argv[3];

    /* Convert num1 to linked list */
    for (int i = 0; num1[i] != '\0'; i++)
    {
        if (num1[i] >= '0' && num1[i] <= '9')
            insert_at_last(head1, tail1, num1[i] - '0');
        else
        {
            printf("Invalid character in first operand!\n");
            exit(1);
        }
    }

    /* Convert num2 to linked list */
    for (int i = 0; num2[i] != '\0'; i++)
    {
        if (num2[i] >= '0' && num2[i] <= '9')
            insert_at_last(head2, tail2, num2[i] - '0');
        else
        {
            printf("Invalid character in second operand!\n");
            exit(1);
        }
    }
}
