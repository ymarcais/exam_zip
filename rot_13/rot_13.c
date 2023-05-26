#include <unistd.h>

int main(int ac, char **av)
{
    char *str;
    char    car = 0;

    str = av[1];
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(*str)
    {
        if ((*str >='a' && *str <= 'm') || (*str >='A' && *str <= 'M'))
        {
            car = *str + 13;
            write(1, &car, 1);
        }
        else if ((*str >= 'n' && *str <= 'z') || (*str >='N' && *str <= 'Z'))
        {
            car = *str - 13;
            write(1, &car, 1);
        }
        else
            write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return (0);
}