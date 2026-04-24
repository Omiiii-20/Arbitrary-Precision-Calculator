
#include "apc.h"

/* Function to print a doubly linked list */
void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Dlist *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Function to free a doubly linked list */
void free_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    while (temp)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
}

/* Function to insert a node at the end of the list */
void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    if (!new)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
}

/* Compare two linked lists numerically */
int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = head1, *t2 = head2;

    while (t1) { len1++; t1 = t1->next; }
    while (t2) { len2++; t2 = t2->next; }

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    t1 = head1;
    t2 = head2;
    while (t1 && t2)
    {
        if (t1->data > t2->data) return 1;
        if (t1->data < t2->data) return -1;
        t1 = t1->next;
        t2 = t2->next;
    }

    return 0; // equal
}


/* Helper function to insert a digit at the beginning of the result list */
/* insert_at_first removed (defined elsewhere) */
