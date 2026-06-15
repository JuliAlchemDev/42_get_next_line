#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Discovering how use open & read functions   
/*
int main(void) {
    char buffer[20];

    int fd = open("text.txt", O_RDONLY);
    read(fd, buffer, 12);
    write(1, buffer, 12);
    close(fd);
    return (0);
}
*/

// Reading text.txt byte by byte 
/*
int main(void) {
    char buffer[20];
    
    int fd = open("text.txt", O_RDONLY);
    int bytes_read = read(fd, buffer, 1);

    printf("Bytes in buffer: %d\n", bytes_read); // 1

    while(bytes_read > 0)
    {
    write(1, &buffer, 1);
    bytes_read = read(fd, buffer, 1);
    }
    close(fd);
    return (0);
}
*/

// Reading in chunks of BUFFER_SIZE, writing only bytes_read to avoid garbage

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
#endif
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 playground.c -o test
int main(void) {
    char buffer[BUFFER_SIZE + 1];
    
    int fd = open("text.txt", O_RDONLY);
    int bytes_read = read(fd, buffer, BUFFER_SIZE);
     
    while(bytes_read > 0)
    {
    write(1, &buffer, bytes_read);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    close(fd);
    return (0);
} // Hello World!%  


