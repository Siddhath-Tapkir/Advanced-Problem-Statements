#include<stdio.h>
#include<stdbool.h>

// Input :  145
// Output : 5! + 4! + 1!
//          120 + 24 + 1
//          145
//          true
bool CheckStrong(int iNo)
{
    auto int iDigit = 0, iTemp = iNo, iSum = 0;

    int Factorial[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + Factorial[iDigit];
        iNo = iNo / 10;
    }

    return (iSum == iTemp);
}

int main()
{

    auto int iValue = 0;
    auto bool bRet = false;

    printf("ENter number\n");
    scanf("%d",&iValue);

    bRet = CheckStrong(iValue);

    if(bRet)
    {
        printf("%d is strong number\n",iValue);
    }
    else
    {
        printf("%d is not strong number\n",iValue);
    }

    return 0;
}