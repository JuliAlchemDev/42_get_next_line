#include "get_next_line.h"

#include <stdio.h> 

#define CYAN   "\033[36m"
#define VIOLET   "\033[94m"
#define PINK        "\033[38;5;205m"
#define PEACH  "\033[38;5;217m"

#define PURPLE      "\033[1m"
#define RESET     "\033[0m"

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o test 
// ./test
// ./test text_1.txt
// ./test text.txt

static void print_slow(char *str, char *color)
{
    int i;
    i = 0;
    while(str[i])
    {
        printf("%s" PURPLE "%c" RESET, color, str[i]);
        fflush(stdout);
        usleep(55000);
        i++;
    }
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
    
    if(argc < 2)
    {
        print_slow("Adjust text file to execute program,\n", VIOLET);
        print_slow("like: './test <filename>' ", VIOLET);
        printf(PEACH "(n_n)\n" RESET);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        print_slow("Oh no!\n", PINK);
        printf(PEACH "       @_@" RESET);
        print_slow("\nSomething went wrong. Try again!\n", PINK);
        return (1);
    }
    print_slow("Reading file:\n\n", VIOLET);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf(CYAN "%s" RESET, line);
        fflush(stdout); 
        usleep(300000);       
        free(line);
    }
    usleep(300000);
    print_slow("\n\nTa-da! ", VIOLET);
    printf(PEACH "\\(^-^)/\n" RESET);
    close(fd);
    return (0);    
}
