#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Discovering how use open & read functions   

int main(void) {
    char buffer[20];

    int fd = open("text.txt", O_RDONLY);
    read(fd, buffer, 12);
    write(1, buffer, 12);
    close(fd);
    return (0);
}



