#include <stdio.c>
void keyCheck()
{
    const char OS[6] = {"Other"}; //Allocate 6 spaces
    int passMe{0};
    identify(passMe, OS); //Pass a value to identify
}

void otherTasks()
{
    printf("Cannot identify the host OS\nAborting program");

}

void execute()
{
    otherTasks();
    exit();
}