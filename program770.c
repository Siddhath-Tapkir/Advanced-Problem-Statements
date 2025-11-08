#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

int Maximum(IPPTR Arr, int iRow, int iCol)
{
    int iMax = 0;

    iMax = INT_MIN;

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(iMax < Arr[i][j])
            {
                iMax = Arr[i][j];
            }
        }
    }
    
    return iMax;
}

int Minium(IPPTR Arr, int iRow, int iCol)
{
    int iMin = 0;

    iMin = INT_MAX;

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(iMin > Arr[i][j])
            {
                iMin = Arr[i][j];
            }
        }
    }
    
    return iMin;
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

void MaximumRow(IPPTR Arr, int iRow, int iCol)
{
    int iMax = 0;

    iMax = INT_MIN;

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(iMax < Arr[i][j])
            {
                iMax = Arr[i][j];
            }
        }

        printf("Maximum element from row no %d is %d\n",i,iMax);
        iMax = INT_MIN;
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

    MaximumRow(Arr,iRow,iCol);

    // Deallocate memory of matrix
    for(int i = 0; i < iRow; i++)
    {
        free(Arr[i]);
    }

    free(Arr);
    
    return 0;
}