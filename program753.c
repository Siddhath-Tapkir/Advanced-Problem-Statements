#include<stdio.h>
#include<stdbool.h>

// Magic number
// Input : 19
// 1 + 9 = 10
// 1 + 0 = 1
// true

bool CheckMagic(int iNo)
{
    if(iNo < 0)
    {
        iNo = -(iNo);
    }
    auto int iDigit = 0, iSum = 0;

    iSum = iNo;

    while(iSum > 9)
    {
        iNo = iSum;

        iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iDigit + iSum;
            iNo = iNo / 10;
        }
    }
    return (iSum == 1);
}

int main()
{

    auto int iValue = 0;
    auto bool bRet = false;

    printf("ENter the Number\n");
    scanf("%d",&iValue);

    bRet = CheckMagic(iValue);

    if(bRet)
    {
        printf("%d is magic number\n",iValue);
    }
    else
    {
        printf("%d is not\n",iValue);
    }

    return 0;
}