#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char *argv[]){
    
    if (argc < 2){
        printf("Usage: %s [file name] ... \n", argv[0]);
        return 0;
    }

    int fd;

    for (int i = 1; i < argc; i++ ){
        fd = open(argv[i], O_RDONLY);

        if (fd == -1){
            perror(argv[i]);
        }

        else{
            printf("Opened successfully: %s (fd = %d)\n", argv[i], fd);
            
            close(fd);
            printf("Closed successfully: %s\n", argv[i]);
        }
    }

   return 0;
}