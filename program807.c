#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


// XOR Cipher
void Encrypt_XOR_Cipher(char *Src, char *Dest, char Key)
{
    int fdSrc = 0, fdDest = 0;

    fdSrc = open(Src,O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Unable to open source file\n");
        return;
    }

    fdDest = open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return;
    }



}

int main()
{
    auto char SrcName[50] = {'\0'};
    auto char DestName[50] = {'\0'};
    auto char Key = '\0';

    printf("Enter the name of original file\n");
    scanf(" %s",SrcName);

    printf("Enter the name of new encrypted file\n");
    scanf(" %s",DestName);

    printf("Enter the key for encryption\n");
    scanf(" %c",&Key);

    Encrypt_XOR_Cipher(SrcName,DestName,Key);


    return 0;
}