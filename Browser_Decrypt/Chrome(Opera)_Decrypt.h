#pragma once
#ifndef _Decrypt_
#define _Decrypt_
#include <windows.h>
#include <iostream>
using namespace std;

string getChromeProfilePath();
string getOperaProfilePath();
string Decrypt(const unsigned char* password, int len);
string Password_Handle(char* input);
char* U2G(const char* utf8);
void ChromeRun();
void OperaRun();

#endif // !_Chrome(Opera)_Decrypt_
