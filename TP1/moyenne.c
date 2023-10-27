#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        puts("no params entered");
        return 1;
    }
    float sum = 0;
    for (int i = 1; i < argc; i++)
    {
        float note;
        // float note = atof(argv[i]);
        sscanf(argv[i],"%f",&note);
        if (note >= 0 && note <= 20)
        {
            sum += note;
        }
        else
        {
            printf("%s is not valid\n", argv[i]);
            return 1;
        }
    }
    
    printf("%f\n", sum/(argc-1));
}
