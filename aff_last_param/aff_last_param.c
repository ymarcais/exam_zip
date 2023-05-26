#include <unistd.h>

int main(int ac, char **av)
{
    char    *str;

    str = av[ac - 1];
    if (ac < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return (0);
}