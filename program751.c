#include<stdio.h>
#include<stdbool.h>

// Amstrong number

// Input : 153
// 1^3 + 5^3 + 3^3
// 1 + 125 + 27
// 153
// true

int Power(int A, int B) // A^B
{
    int iResult = 1;
    int i = 0;

    for(i = 1; i <= B; i++)
    {
        iResult = iResult * A;
    }

    return iResult;
}

int CountDigit(int iNo)
{
    int iCount = 0;

    while(iNo != 0)
    {
        iCount++;
        iNo = iNo / 10;
    }

    return iCount;
}

bool CheckArmStrong(int iNo)
{
    int iSum = 0, iTemp = iNo, iDigit = 0;
    int iCount = 0;

    iCount = CountDigit(iNo);

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + Power(iDigit,iCount);
        iNo = iNo / 10;
    }

    return (iTemp == iSum);
}

int main()
{

    auto int iValue = 0;
    auto bool bRet = false;

    printf("ENter the Number\n");
    scanf("%d",&iValue);

    bRet = CheckArmStrong(iValue);

    if(bRet)
    {
        printf("%d is Armstrong number\n",iValue);
    }
    else
    {
        printf("%d is not\n",iValue);
    }

    return 0;
}