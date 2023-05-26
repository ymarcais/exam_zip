#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char    *str;

    str = av[1];
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(*str == ' ' || *str == '\t' || *str == '\n')
    {
        str++;
    }
    if (*str == '\0')
    {
        write(1, "\n", 1);
        return(0);
    }
    while(*str)
    {
        if (*str != ' ' && *str != '\n' && *str != '\t')
            write(1, str, 1);
        if(*str == ' ' || *str == '\t' || *str == '\n')
            break;
        str++;
    }
    write(1, "\n", 1);
    return (0);
}
