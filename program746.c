#include<stdio.h>
// 9875
// 9 + 8 + 7 + 5 = 29 
// 2 + 9 = 11
// 1 + 1 = 2
// return 2

int GenericRoot(int iNo)
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
    return iSum;
}

int main()
{

    auto int iValue = 0, iRet = 0;

    printf("ENter number\n");
    scanf("%d",&iValue);

    iRet = GenericRoot(iValue);

    printf("Generic root of %d is %d\n",iValue,iRet);

    return 0;
}