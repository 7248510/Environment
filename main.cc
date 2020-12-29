#include <iostream>
#include "identify.c"
#include "win32.cc" //Fix Linux dependency errors(I need to figure out how to seperate windows header files and Linux headers)
//cl main.cc /EHsc && main.exe
//cl test.cc /EHsc && test.exe
int main()
{
    int getOS;
    getOS = identify();
    std::cout << "OS VAL: "<< getOS;
    /*
    //VIRTUAL MACHINE WINDOWS CONFIGURATION
    netUser windowsVM;
    windowsVM.changePassword(); //Removing the default password.
    */
    //int determineOS;
    //determineOS = getOS();
    //std::cout << determineOS;

    //identify testIdentify;
    //identify getOS();
    //process testLaunch;
    //testLaunch.createProc();
    //std::cout << "Correct program";
}