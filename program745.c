#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

int Count(PNODE first)
{
    auto int iCount = 0;

    while(first)
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first -> next;
    }

    printf("NULL\n");
}

void ReverseLinkedList(PPNODE first)
{
    PNODE Previous = NULL;
    PNODE Current = NULL;
    PNODE Next = NULL;

    if(NULL == *first)
    {
        return;
    }

    Current = *first;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next = Previous;
        Previous = Current;
        Current = Next;
    }
    *first = Previous;
}

void ReversedLinkedListSpace(PPNODE first)
{
    int *Arr = NULL;
    int iSize = 0, i = 0;
    PNODE temp = *first;

    if(NULL == *first)
    {
        return;
    }

    iSize = Count(*first);

    Arr = (int *)malloc(sizeof(int) * iSize);   // Space Complexity

    while(temp != NULL)
    {
        Arr[i] = temp->data;
        i++;
        temp = temp->next;
    }

    temp = *first;

    i = iSize - 1;

    while(temp != NULL)
    {
        temp->data = Arr[i];
        i--;
        temp = temp->next;
    }

    free(Arr);
}

int main()
{
    PNODE head = NULL;

    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,101);
    InsertLast(&head,111);
    Display(head);

    // Time Complexity :    O(3N)   Where N is the size of LinkedList
    // Space Complexity :   O(N)    Where N is the size of LinkedList
    
    ReversedLinkedListSpace(&head);
    Display(head);
    return 0;
}