#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
    int son = fork();
    if (son)
    {
        while (1)
        {
            puts("Coucou papa :)");
            sleep(1);
        }
    }
    else{
        for (size_t i = 0; i < 5; i++)
        {
            puts("Bonjour fils !");
            sleep(1);
        }
        kill(son, SIGTERM);
    }
    
    return 0;
}
