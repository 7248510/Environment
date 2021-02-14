// typedef const wchar_t *LPCWSTR; = LPCWSTR which is required(netuserchangepassword function)
//https://docs.microsoft.com/en-us/cpp/cpp/char-wchar-t-char16-t-char32-t?view=vs-2019
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")
#include <windows.h> //Windows header
#include <cstdio> //C function
#include <iostream> //standard library
#include <lm.h> //nstatus
#include <Processthreadsapi.h> //Create proccess
#include <Errhandlingapi.h> //Error handling
#include "identify.c"
#include <chrono> //Timer
#include <thread>
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
    int dockerLaunch() //Unfortunately on Windows 10 Home the only service created is Docker Desktop Service. I could not figure out nor find out how to launch docker without the Desktop
    {
        SecureZeroMemory(&startInfo, sizeof(startInfo)); //Running a more secure version of zero memory. This function "fills a block of memeory with zeros from MSDN"
        //LPCWSTR applicationName = L"C:\\Windows\\System32\\notepad.exe";
        std::cout << "\nLaunching Docker\n";
        LPCWSTR applicationName = L"C:\\Program Files\\Docker\\Docker\\Docker Desktop.exe"; //Fixed the error. Missing an e in exe
        int application;
        application = CreateProcess(applicationName,NULL,NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags  
        //std::cout << errorCode;  
        if (application == 1) {
            std::cout << "\nDocker launched.\n";
        } 
        if (application != 1) {
            std::cout << "\nCreate processes resulted in an error\nError code value: " << application << "\n";
        }
        if (application == 0) {
            std::wcout << "\n" << applicationName << " not found";
            //https://stackoverflow.com/questions/32338496/what-is-the-difference-between-stdcout-and-stdwcout
            //cout utilizes char
            //wcout utilized wchar_t which the Windows API utilizes
        }
        return 0;//Function executes 
    }
    int dockerNodes() 
    {
        //Testing. I'll clean up the function later.
        //Vectors would be more efficient
        SecureZeroMemory(&startInfo, sizeof(startInfo)); //Running a more secure version of zero memory. This function "fills a block of memeory with zeros from MSDN"
        LPWSTR listContainers = L"docker container list"; //Fixed the error. Missing an e in exe
        //LPWSTR nodes[2];
        const char * nodes[2]; //Alloc 3 spaces
        std::string start, stop, restart;
        /*
        nodes[0] = L"docker container start nodeTest";
        nodes[1] = L"docker container stop nodeTest"; //Testing if both processes execute okay
        nodes[2] = L"docker container start nodeTest"; //does not loop well.
        */
        nodes[0] = "docker container start nodeTest";
        nodes[1] = "docker container stop nodeTest"; //Testing if both processes execute okay
        nodes[2] = "docker container start nodeTest"; //does not loop well.
        //CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[0],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo);
        std::system(nodes[0]);
        std::system(nodes[1]);
        std::system(nodes[2]);
        //CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[1],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo);
        //CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[2],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo);
        /*
        start = CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[0],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags 
        std::cout << "\n" << "Starting: "<< start; 
        stop = CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[1],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags 
        std::cout << "\n" << "Stop: "<< stop; 
        //commandOutput = CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",nodes[2],NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags 
        std::cout << "\n" << "Starting: "<< restart; 
        */
        return 0;
    }
    int dockerList() 
    {
        SecureZeroMemory(&startInfo, sizeof(startInfo)); //Running a more secure version of zero memory. This function "fills a block of memeory with zeros from MSDN"
        LPWSTR listContainers = L"docker container list"; //Fixed the error. Missing an e in exe
        std::string commandOutput;
        commandOutput = CreateProcess(L"C:\\Program Files\\Docker\\Docker\\resources\\docker.exe",L"docker container list",NULL,NULL,FALSE, 0,NULL,NULL,&startInfo,&procInfo); //https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags 
        std::cout << "\n" << commandOutput; 
        return 0;
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
    //netUser windowsVM;
    processes procLaunch;
    //windowsVM.changePassword(); //Removing the default password.
    //procLaunch.createProc(); //testing test
    procLaunch.dockerLaunch();
    std::this_thread::sleep_for (std::chrono::seconds(10)); //Wait 20 seconds for Docker desktop to start. This pauses the current thread this program(variant) is designed to be launched at startup
    procLaunch.dockerNodes();
    //procLaunch.dockerList();
}


std::string keyCheck()
{
    std::string output;
    const char OS[8] = {"Windows"};// = "Windows";// = {"Windows"}; //Allocate 8 spaces
    int passMe{1};
    output = identify(passMe, OS); //Pass a value to identify
    std::cout << output << "\n";
    return output;
}
void execute() {
    windowsTasks(); 
}
