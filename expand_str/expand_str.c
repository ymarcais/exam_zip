#include<stdlib.h>
#include<unistd.h>

int ft_space(char c)
{
    return (c >= 9 && c<= 13) || c == 32;
}

int main(int ac, char **av)
{
    char *str;
    int len = 0;

    str = av[1];
    if (ac != 2 || str == NULL)
    {
        write(1, "\n", 1);
        return 0;
    }
    while (*str)
    {
        len++;
        str++;
    }    
     str--;
    while(ft_space(*str))
    {
        *str = '\0';
        str--;
    }
    str = av[1];
    while(ft_space(*str))
        str++;
    while(*str)
    {
        if(*str && !ft_space(*str))
            write(1, str, 1);
        else if (ft_space(*str) && !ft_space(*(str + 1)))
            write(1, "   ", 3);
        str++;
    }
    write(1, "\n", 1);
    return 0;    
}

