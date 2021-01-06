#include <iostream>
#include "identify.c"
//Fix Linux dependency errors(I need to figure out how to seperate windows header files and Linux headers)
//cl main.cc /EHsc && main.exe
//cl test.cc /EHsc && test.exe
int main()
{
    int getOS;
    getOS = identify();
    std::cout << "OS VAL: " << getOS;
    if (getOS = 1) {
        #include "win32.cc";
        std::cout << "Starting Windows tasks.";
        windowsTasks();
    }
    if (getOS = 2) {
        #include "linux.c";
    }
    //testLaunch.createProc();
    //std::cout << "Correct program";
}