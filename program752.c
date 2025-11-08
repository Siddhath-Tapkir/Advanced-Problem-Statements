#include<stdio.h>
#include<stdbool.h>

// Harshad number

// Input : 18
// 18 -> 1 + 8 = 9
// 18 % 9 == 0
// true

bool CheckHarshad(int iNo)
{
    auto int iSum = 0, iTemp = iNo, iDigit = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;

        iSum = iDigit + iSum;

        iNo = iNo / 10;
    }

    return (iTemp % iSum == 0);
}
int main()
{

    auto int iValue = 0;
    auto bool bRet = false;

    printf("ENter the Number\n");
    scanf("%d",&iValue);

    bRet = CheckHarshad(iValue);

    if(bRet)
    {
        printf("%d is harshad number\n",iValue);
    }
    else
    {
        printf("%d is not\n",iValue);
    }

    return 0;
}