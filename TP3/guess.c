#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // create pipe
    int pip[2];
    pipe(pip);
    int pip2[2];
    pipe(pip2);



    if (fork() == 0){
        int receive;
        close(pip[1]);
        read(pip[0], &receive, sizeof(int));
        close(pip[0]);
        printf("%d\n", receive);
        int random = rand() % 11;
        char res;

            close(pip2[0]);
            if (receive == random)
            {
                res = '=';
            }else if(receive < random){
               res = '+';
            }else if(receive > random){
                res = '-';
            }
            write(pip2[1], &res, sizeof(char));
            close(pip2[1]);

        
        
    }
    else{
        char res;
        int nombre;
            close(pip[0]);
            puts("Enter a number to pass to the child process :");
            scanf("%d", &nombre);
            write(pip[1], &nombre, sizeof(int));
            close(pip[1]);
            close(pip2[1]);
            read(pip2[0], &res, 1);
            printf("%c\n", res);
            close(pip2[0]);
        
    }
    return 0;
}
