#include <unistd.h>

void	ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
}

int main(int ac, char **av)
{
    char *str;

    str = av[ac - 1];
    ft_putstr(str);
    return (0);
}