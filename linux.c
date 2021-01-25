
#include <unistd.h> //For avoiding errors compiling on windows
#include <stdio.c>

void keyCheck()
{
    const char OS[6] = {"Linux"}; //Allocate 6 spaces
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