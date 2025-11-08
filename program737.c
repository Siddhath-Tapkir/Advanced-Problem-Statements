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

        if((temp->next == NULL) && (temp->data == No))
        {
            free(newn);
            return;
        }

        if(temp->next != NULL)
        {
            if((temp->next->data == No) || (temp->data == No))
            {
                free(newn);
                return;
            }
        }

        newn->next = temp->next;
        temp->next = newn;        
    }
}

int MiddleElement(PNODE first)
{
    int iCount = 1, Middle = 0;
    PNODE temp = first;

    while(temp)
    {
        temp = temp->next;
        iCount++;
    }

    Middle = iCount / 2;

    printf("Middle index is : %d\n",Middle);

    for(iCount = 1; iCount < Middle; iCount++)
    {
        first = first->next;
    }

    return (first->data);
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

    

    Display(head);

    printf("Middle element is : %d\n",MiddleElement(head));


    return 0;
}