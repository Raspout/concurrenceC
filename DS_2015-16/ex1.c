#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n = 2;
    int pid;
    for (int i = 0; i < n; i++)
    {
        printf("i=%d\n", i);
        int pid;
        pid = fork();
        if (pid == -1)
        {
            perror("erreur fork");
            exit(1);
        }
        else{
            if (pid != 0)
            {
                printf("processus = %d\n", pid);
            }
            
        }
        

    }
    
    return 0;
}
