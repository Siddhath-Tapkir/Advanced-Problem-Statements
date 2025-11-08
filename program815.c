// EncryptDecryptClient.cpp file contents

#include<iostream>
using namespace std;
#include<windows.h>
#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef void (*FPTR)(char *, char *, int);

int main()
{
    HINSTANCE hdll = LoadLibrary("EncryptDecryptClient.dll")

    if(hdll == NULL)
    {
        std::cout<<"Unable to load library\n";
        return -1;
    }

    FPTR fp = (FPTR)GetProcAddress(hdll,"Encrypt_Caesar_Cipher");

    if(fp == NULL)
    {
        std::cout<<"Unable to get address of function\n";
        return -1;
    }

    fp("Input.txt","Output.txt",21);

    FreeLibrary(hdll);

    return 0;
}
// This application should use EncryptDecrypt.dll
// This .dll should be placed in x64/debug

// This is the client which uses the dll and access the functionality of encryption and decryption