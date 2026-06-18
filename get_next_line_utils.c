#include "get_next_line.h"

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

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    const char *s;
    size_t i;

    d = dst;
    s = src;
    i = 0;
    while(i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}

char *ft_strjoin(const char *str_1, const char *str_2)
{
    char *join;
    size_t len_1;
    size_t len_2;
    
    if(!str_2)
        return (NULL);
    len_1 = ft_strlen(str_1); 
    len_2 = ft_strlen(str_2); 
    
    join = malloc(len_1 + len_2 + 1);
    if(!join)
        return (NULL);
    ft_memcpy(join, str_1, len_1);
    ft_memcpy(join + len_1, str_2, len_2);
    join[len_1 + len_2] = '\0';
    return (join);
}

char *ft_substr(const char *str, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    size_t s_len;

    if(!str)
        return (NULL);
    s_len = ft_strlen(str);
    if(start >= s_len)
        len = 0;
    else if(len > s_len - start)
        len = s_len - start;
    substr = malloc(len + 1);
    if(!substr)
        return (NULL);
    i = 0;
    while(i < len)
    {
        substr[i] = str[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);   
}

/*
#include <stdio.h> 

#define PURPLE      "\033[38;5;93m"
#define RESET     "\033[0m"

int main()
{
    char *test_str_1;
    char *test_str_2;
    char *result;

    test_str_1 = "Twinkle, twinkle, little star,\nHow I wonder what you are!";
    test_str_2 = NULL; 
    printf(PURPLE "Len of the str:" RESET " %zu\n", ft_strlen(test_str_1)); // Len of the str: 57 
    printf(PURPLE "NULL  case:" RESET " %zu\n", ft_strlen(test_str_2)); // NULL  case:  0

    printf(PURPLE "First occurrence of '\\n':" RESET " %s\n", ft_strchr(test_str_1, '\n')); // First occurrence of '\n': How I wonder what you are!
    printf(PURPLE "NULL string case:" RESET " %s\n", ft_strchr(test_str_2, '\n')); // NULL string case: (null)

    result = ft_strjoin("Twinkle, twinkle,", " little star,");
    printf(PURPLE "Join:" RESET " %s\n", result); // Join: Twinkle, twinkle, little star,
    free(result);
    result = ft_strjoin("Twinkle, twinkle,", NULL);
    printf(PURPLE "Join with NULL:" RESET " %s\n", result); // Join with NULL: (null)
    free(result);

    result  = ft_substr(test_str_1, 25, 4); 
    printf(PURPLE "Extract 'star' from string 1:" RESET " %s\n", result); 
    free(result);
    result  = ft_substr(NULL, 25, 4); 
    printf(PURPLE "Test ft_substr with NULL as a string:" RESET " %s\n", result); 
    free(result);
}
*/