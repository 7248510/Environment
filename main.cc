#include <iostream>
    #if _WIN32
        #include "win32.cc"
    #endif
    #if __linux__
        #include "linux.cc"
    #endif
int main()
{
    std::string identifyHost;
    identifyHost = keyCheck();
    std::cout << identifyHost;
    //Call one of the methods
}


























