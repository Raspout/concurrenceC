//wc < /etc/passwd
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    
    int file = open("/etc/passwd", O_RDONLY);
    // Execute wc avec les données du fichier
    dup2(file, 0);
    close(file);
    execlp("wc", "wc", NULL);

}
