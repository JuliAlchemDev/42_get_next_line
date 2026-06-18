#include "get_next_line.h"
#include <stdio.h> 

char *read_and_save(int fd, char *save)
{
    char *chunk;
    int bytes_read;

    chunk = malloc(BUFFER_SIZE + 1);
    if(!chunk)
        return (NULL);
    bytes_read = read(fd, chunk, BUFFER_SIZE);
    while(!ft_strchr(save, '\n') && bytes_read > 0) 
    {
        chunk[bytes_read] = '\0';
        save = ft_strjoin(save, chunk);
        bytes_read = read(fd, chunk, BUFFER_SIZE);
    }
    free(chunk);
    return (save);
}

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