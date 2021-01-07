#include <stdio.c>
void keyCheck()
{
    std::string OS = {"Other"}; //Allocate 5 spaces
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