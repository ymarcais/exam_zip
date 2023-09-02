#include <unistd.h>

int main(int ac, char **av)
{
    char    *str;

    if (ac != 2)
    {
        write(1, "a\n", 2);
        return(0);
    }
    str = av[1];
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
