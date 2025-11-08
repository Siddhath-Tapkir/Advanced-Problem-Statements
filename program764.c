#include<stdio.h>
#include<stdlib.h>

typedef int * IPTR;
typedef int ** IPPTR;

int Summation(IPPTR Arr, int iRow, int iCol)
{
    int iSum = 0;
    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            iSum = Arr[i][j] + iSum;
        }
    }
    
    return iSum;
}

void Accept(IPPTR Arr, int iRow, int iCol)
{
    printf("Enter the elements\n");

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            scanf("%d",&Arr[i][j]);
        }
    }
}

void Display(IPPTR Arr, int iRow, int iCol)
{
    printf("Elements of the matrix are\n");

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            printf("%d\t",Arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    IPPTR Arr = NULL;

    auto int iRow = 0, iCol = 0, iRet = 0;

    printf("Enter Number of rows\n");
    scanf("%d",&iRow);

    printf("Enter Number of columns\n");
    scanf("%d",&iCol);

    Arr = (IPPTR)malloc(sizeof(IPTR) * iRow);

    for(int i = 0; i < iRow; i++)
    {
        Arr[i] = (IPTR)malloc(sizeof(int) * iCol);
    }

    Accept(Arr,iRow,iCol);
    
    Display(Arr,iRow,iCol);

    iRet = Summation(Arr,iRow,iCol);

    printf("Summation of elements of matrix is : %d\n",iRet);

    // Deallocate memory of matrix
    for(int i = 0; i < iRow; i++)
    {
        free(Arr[i]);
    }

    free(Arr);
    
    return 0;
}