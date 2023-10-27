#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char* args[argc];
    char* o[argc - 1];
    char* out[argc - 1];
    args[0] = "gcc";
    for (int i = 1; i < argc; i++){
        args[i] = argv[i];
        o[i-1] = argv[i];
        o[i-1][strlen(o[i-1])] = "o";
        out[i-1] = argv[i];
        out[i-1][strlen(out[i-1])-1] = 0;
    }
    

    if (fork() ==  0){
        execvp("gcc", args);
    }
    return 0;
}

