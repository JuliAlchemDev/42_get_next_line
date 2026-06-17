#include "get_next_line.h"

#include <stdio.h> // DELETE after test

size_t ft_strlen(const char *str)
{
    int i;

    if(!str)
        return (0); // unlike strlen, ft_strlen handles NULL safely
    i = 0;
    while(str[i])
        i++;
    return (i);
}

int main()
{
    char *test_str;
    test_str = "Twinkle, twinkle, little star,\nHow I wonder what you are!";
    printf("Len of the str: %zu\n", ft_strlen(test_str)); // Len of the str: 57
    test_str = NULL; 
    printf("Len of the str: %zu\n", ft_strlen(test_str));
}

