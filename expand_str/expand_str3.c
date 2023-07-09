#include<stdlib.h>
#include<unistd.h>

int ft_space(char c)
{
    return (c >= 9 && c <= 13) || c == 32;
}

int ft_no_word(char *str)
{
   int  len = 0;
   int  space = 0;

   while(*str)
    {
        if(ft_space(*str))
            space++;
        len++;
        str++;
    }
    return len == space;
}

int main(int ac, char **av)
{
    char *str;
    int len = 0;

    if(ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    str = av[1];
    while(*str)
    {
        len++;
        str++;
    }
    str = av[1];
    if (str == NULL || ft_no_word(str))
    {
        write(1, "\n", 1);
        return 0;
    }
    str = av[1];
    len--;
    while(ft_space(str[len]))
    {
        str[len] = '\0';
        len--;
    }
    while(ft_space(*str))
        str++;
    while(*str)
    {
        if(*str && !ft_space(*str))
            write(1, str, 1);
        else if(ft_space(*str))
        {
            if(!ft_space(*(str + 1)))
                write(1, "   ", 3);
        }
        str++;
    }
    return (0);  
}