#include<stdio.h>
#include<stdbool.h>
// Strong number, Peterson number
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

void CheckStrongRange(int iEnd)
{
    auto bool bRet = false;
    for(int iCnt = 1; iCnt <= iEnd; iCnt++)
    {
        bRet = CheckStrong(iCnt);
        if(bRet)
        {
            printf("%d is strong number\n",iCnt);
        }
    }
}
int main()
{

    auto int iValue = 0;
    auto bool bRet = false;

    printf("ENter the end point of the range\n");
    scanf("%d",&iValue);

    CheckStrongRange(iValue);


    return 0;
}