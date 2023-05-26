#include <unistd.h>

int main(int ac, char **av)
{
    char    *str;

    str = av[1];

    if (ac != 2)
    {
        write(1, "a\n", 2);
        return(0);
    }
    while(*str)
    {
        if (*str == 'a')
        {
            write(1, "a\n", 2);
            return(0);
        }
        str++;
    }
    write(1, "\n", 1);
    return (0);
}