#define TIME 1000

#ifdef _WIN32
#include <windows.h>
#define CLEAR system("cls")
#define WAIT Sleep(TIME)

#elif __APPLE__
#include <unistd.h>
#define WAIT usleep(TIME*1000)
#define CLEAR system("clear")

#elif __linux__
#include <unistd.h>
#define WAIT usleep(TIME*1000)
#define CLEAR system("clear")
#endif