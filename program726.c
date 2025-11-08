#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

// Node gets inserted in the increasing order
void InsertSortedINC(PPNODE first, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    
    // First element
    if(NULL == *first)
    {
        *first = newn;
    }

    // Second onwards
    else
    {
        if(No < (*first)->data) // If it is less than first element
        {
            newn->next = *first;
            *first = newn;
            return;
        }
        temp = *first;

        while(temp->next != NULL)
        {
            if(temp->data < No && temp->next->data > No)
            {
                break;
            }
            temp = temp->next;
        }
        
        if(NULL == temp->next && No > temp->data)// If it is greater than last element
        {
            temp->next = newn;
            return;
        }

        // If it lies in between the linkedlist
        newn->next = temp->next;
        temp->next = newn;
    }
}

void Display(PNODE first)
{
    while(first)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}
int main()
{
    PNODE head = NULL;

    InsertSortedINC(&head,11);
    InsertSortedINC(&head,7);
    InsertSortedINC(&head,75);
    InsertSortedINC(&head,21);
    InsertSortedINC(&head,51);
    InsertSortedINC(&head,40);
    InsertSortedINC(&head,31);
    InsertSortedINC(&head,51);
    

    Display(head);


    return 0;
}