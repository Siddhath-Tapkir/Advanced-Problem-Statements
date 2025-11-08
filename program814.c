// EncryptDecrypt.cpp file contents

#include<windows.h>
#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_SIZE 1024

// Caesar Cipher

// Replace open with _open
// Replace read with _read


extern "C" declspec(dllexport) void Encrypt_Caesar_Cipher(char *, char *, int);

void Encrypt_Caesar_Cipher(char *Src, char *Dest, int Key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;

    char Buffer[MAX_SIZE] = {'\0'};
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

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%d\n",iRet);
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + Key) % 256;
        }
        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
}

extern "C" declspec(dllexport) void Decrypt_Caesar_Cipher(char *, char *, int);

void Decrypt_Caesar_Cipher(char *Src, char *Dest, int Key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;

    char Buffer[MAX_SIZE] = {'\0'};
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

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%d\n",iRet);
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - Key) % 256;
        }
        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
}

// XOR Cipher
extern "C" declspec(dllexport) void Encrypt_XOR_Cipher(char *, char *, char);


void Encrypt_XOR_Cipher(char *Src, char *Dest, char Key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;

    char Buffer[MAX_SIZE] = {'\0'};
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

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%d\n",iRet);
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }
        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
}

extern "C" declspec(dllexport) void Decrypt_XOR_Cipher(char *, char *, char);

void Decrypt_XOR_Cipher(char *Src, char *Dest, char Key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;

    char Buffer[MAX_SIZE] = {'\0'};
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

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }
        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
}

// This application should create EncryptDecrypt.dll

// dllmain.cpp file is as it is