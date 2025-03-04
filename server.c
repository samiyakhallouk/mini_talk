#include "minitalk.h"


void    handler(int signum)
{
    printf("Received SIGINT!\n", signum);
    exit(0);
}


int main(void)
{
    int p = getgid();
    printf("pid is : %d\n", p);
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1)
    {
        pause();
    }
    
    
    
    return 0;
}