#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    puts(".");
    int a,b,c;
    puts(".");
    a = fork();
    puts(".");
    b = fork();

    if (b == 0)
    {
        puts(".");
        c = fork();
    }
}
