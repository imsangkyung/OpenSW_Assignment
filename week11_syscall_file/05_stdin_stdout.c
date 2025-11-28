#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define BUF_SIZE 128

int main(int argc, char* argv[]){
    
    if (argc != 1){
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }
    
    char readStr[BUF_SIZE];

    while(1){
        int read_result = read(0, readStr, BUF_SIZE);

        if (read_result == 0){
            break;
        }

        write(1, readStr, read_result);
    }

    return 0;
}

