#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int len = strlen(argv[i]);
        for (int y = 1; y < len+1; y++)
        {
            printf("%c", argv[i][len - y]);
        }
        printf(" ");
    }
    printf("\n");
}
