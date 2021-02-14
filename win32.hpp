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
#include <chrono> //Timer
#include <thread> //Timer