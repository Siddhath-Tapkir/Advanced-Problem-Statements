#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

// Node gets inserted in the increasing order
void InsertSortedINCUnique(PPNODE first, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    
    if((NULL == *first) || (No < (*first)->data))
    {
        newn->next = *first;
        *first = newn;
    }
    else
    {
        temp = *first;

        while((temp->next != NULL) && (temp->next->data < No))
        {
            temp = temp->next;
        }

        if(temp->next != NULL)
        {
            if((temp->next->data == No) || (temp->data == No))
            {
                free(newn);
                return;
            }
        }

        if(temp->data != No)
        {
            newn->next = temp->next;
            temp->next = newn;
        }
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

    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
    InsertSortedINCUnique(&head,-11);
   
    
    

    Display(head);


    return 0;
}