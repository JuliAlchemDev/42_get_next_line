#include "get_next_line.h"
#include <stdio.h> 



char *get_next_line(int fd)
{
    static char *save;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    save = read_and_save(fd, save);
    if(!save)
        return (NULL);

    // line = extract_line(save);
    // save = update_save(save);
    
    return (save);
}


int main(void){
    int fd = open("text.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("Final save: %s", line);
    return (0);
}