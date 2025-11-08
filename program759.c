#include<stdio.h>
#include<stdlib.h>

typedef int * IPTR;
typedef int ** IPPTR;

int main()
{
    IPPTR Arr = NULL;

    auto int iRow = 0, iCol = 0;

    printf("Enter Number of rows\n");
    scanf("%d",&iRow);

    printf("Enter Number of columns\n");
    scanf("%d",&iCol);

    Arr = (IPPTR)malloc(sizeof(IPTR) * iRow);

    for(int i = 0; i < iRow; i++)
    {
        Arr[i] = (IPTR)malloc(sizeof(int) * iCol);
    }
    return 0;
}