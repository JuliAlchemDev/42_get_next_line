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

char *ft_strchr(const char *str, int ch)
{
    int i;

    if(!str)
        return (NULL);
    i = 0;
    while(str[i])
    {
        if(str[i] == (char)ch)
            return ((char *)&str[i]);
        i++;
    }
    if(str[i] == (char)ch)
            return ((char *)&str[i]);
    return (NULL);
}

int main()
{
    char *test_str_1;
    char *test_str_2;

    test_str_1 = "Twinkle, twinkle, little star,\nHow I wonder what you are!";
    test_str_2 = NULL; 
    printf("Len of the str: %zu\n", ft_strlen(test_str_1)); // Len of the str: 57 
    printf("NULL  case:  %zu\n", ft_strlen(test_str_2));

    printf("First occurrence of '\\n': %s\n", ft_strchr(test_str_1, '\n')); 
    printf("NULL string case: %s\n", ft_strchr(test_str_2, '\n')); 
}

