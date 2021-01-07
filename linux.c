
#include <unistd.h> //For avoiding errors compiling on windows
#include <stdio.c>

void keyCheck()
{
    std::string OS = {"Linux"};
    int passMe{1};
    identify(passMe, OS); //Pass a value to identify
}

void linuxTasks() {
    printf('No tasks.');
}

void execute()
{
    linuxTasks();
}