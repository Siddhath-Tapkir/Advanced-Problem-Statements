#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool CheckLoop(PNODE first)
{
    bool bFlag = false;

    PNODE teacher = first;
    PNODE student = first;

    while((teacher != NULL) && (teacher->next != NULL))
    {
        teacher = teacher->next->next;
        student = student->next;

        if(teacher == student)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
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

    auto bool bRet = false;
    
    InsertSortedINCUnique(&head,11);
    InsertSortedINCUnique(&head,21);
    InsertSortedINCUnique(&head,51);
    InsertSortedINCUnique(&head,101);
    InsertSortedINCUnique(&head,111);
    InsertSortedINCUnique(&head,121);


    bRet = CheckLoop(head);

    if(true == bRet)
    {
        printf("Loop is there\n");
    }
    else
    {
        printf("Loop is not there\n");
    }


    return 0;
}