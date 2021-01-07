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
#include <Processthreadsapi.h>
#include <Errhandlingapi.h>
#include "identify.c"
//Structures's naming conventions are prone to change throughout the programs life cycle!
struct netUser {
    //Net user structure to hold 
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
struct processes {
    STARTUPINFO startInfo;
    PROCESS_INFORMATION procInfo;
    int createProc()
    { 
        SecureZeroMemory(&startInfo, sizeof(startInfo)); //Running a more secure version of zero memory. This function "fills a block of memeory with zeros from MSDN"
        //LPCWSTR applicationName = L"C:\\Windows\\System32\\notepad.exe";
        LPCWSTR applicationName = L"test.exe";
        int application;
        application = CreateProcess(applicationName,NULL,NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags  
        //std::cout << errorCode;  
        if (application == 1) {
            std::cout << "Program succesfully launched.\n";
        } 
        if (application != 1) {
            std::cout << "Create processes resulted in an error\nError code value: " << application;
        }
        if (application == 0) {
            std::wcout << "\n" << applicationName << " not found";
            //https://stackoverflow.com/questions/32338496/what-is-the-difference-between-stdcout-and-stdwcout
            //cout utilizes char
            //wcout utilized wchar_t which the Windows API utilizes
        }
        return 0;//Function executes  
    } 
    //After the functions have been called the last step is to call a destructor
    ~processes() {
        //CLEAN UP https://docs.microsoft.com/en-us/windows/win32/procthread/creating-processes 
        // Wait until child process exits.
        WaitForSingleObject(procInfo.hProcess, INFINITE);
        // Close process and thread handles. 
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
        std::cout << "\nUtilizing a destructor to exit createprocess.";
    }
};
void windowsTasks()
{
    //VIRTUAL MACHINE WINDOWS CONFIGURATION
    netUser windowsVM;
    processes testLaunch;
    std::cout << "\nRemoving Windows password.\n";
    //windowsVM.changePassword(); //Removing the default password.
    testLaunch.createProc();
    std::cout << "Correct program!\n";
}

std::string keyCheck()
{
    std::string output;
    const char OS[8] = {"Windows"};// = "Windows";// = {"Windows"}; //Allocate 6 spaces
    int passMe{1};
    output = identify(passMe, OS); //Pass a value to identify
    std::cout << output;
    return output;
}
void execute() {
    windowsTasks(); 
}
