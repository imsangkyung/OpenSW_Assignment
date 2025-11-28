#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 32
#define MAX_DESTS 100 

int main(int argc, char * argv[]){
    
    char buf[BUF_SIZE];
    int src_fd;
    ssize_t read_len;
    
    int dest_fds[MAX_DESTS]; 

    if( argc < 2){
        printf("Usage: %s [source file] [destination file1] ... \n", argv[0]);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1){
        perror("Source file open error"); 
        exit(1);
    }

    int num_dests = argc - 2;


    if (num_dests > MAX_DESTS) {
        printf("Error: Too many destination files. Max is %d\n", MAX_DESTS);
        close(src_fd);
        exit(1);
    }

    for (int i = 0; i < num_dests; i++){

        dest_fds[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        
        if (dest_fds[i] == -1) {
            perror("Destination file open error");
            close(src_fd); 
            exit(1);
        }
    }


    while(1){
        read_len = read(src_fd, buf, BUF_SIZE);

        if (read_len == 0) break; 
        if (read_len == -1) {
            perror("Read error");
            break;
        }

        write(STDOUT_FILENO, buf, read_len);


        for (int i = 0; i < num_dests; i++){
            write(dest_fds[i], buf, read_len);
        }
    }


    close(src_fd);
    for (int i = 0; i < num_dests; i++) {
        close(dest_fds[i]);
    }

    return 0;
}