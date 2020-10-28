// typedef const wchar_t *LPCWSTR; = LPCWSTR which is required(netuserchangepassword function)
//https://docs.microsoft.com/en-us/cpp/cpp/char-wchar-t-char16-t-char32-t?view=vs-2019
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")
#include <windows.h> 
#include <cstdio>
#include <iostream>
#include <lm.h>
struct netUser {
    const wchar_t domainName = NULL; //Using the current domain
    const wchar_t userName = NULL; //Using the current logged in user
    const wchar_t *oldPassword = L"Passw0rd!"; //The default microsoft VM password
    const wchar_t *newPassword = L""; //The new password value is blank. I'm removing the password. If you'd like a password type one within the quotes.
    int changePassword() {
        NET_API_STATUS nStatus;
        nStatus = NetUserChangePassword(NULL,NULL,oldPassword,newPassword);
        if (nStatus == 86) {
            std::cout << "You've entered the wrong password in the old password parameter.";
        }
        else 
            std::cout << "The password has been succesfully changed.";
        return 0;
    }
};