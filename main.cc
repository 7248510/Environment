//cl /EHsc test.cc
//cl /EHsc main.cc
//cl /EHsc /I C:\boost_1_75_0 main.cc -D_WIN32_WINNT=0x0601
    #if _WIN32
        //#include "C:\boost_1_74_0\boost\asio.hpp"
        #include "win32.cc"
    #elif __linux__
        #include "linux.cc"
    #else
        #include "other.c"
    #endif
int main()
{
    
    std::string identifyHost;
    identifyHost = keyCheck();
    std::cout << identifyHost;
     //This function will execute regardless of the host OS
    execute();
}