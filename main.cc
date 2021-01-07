    #if _WIN32
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
    execute(); //This function will execute regardless of the host OS
}