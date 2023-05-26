#include <unistd.h>

int    main(int ac, char **av)
{
    char *str;
    char    car;

    car = 0;
    str = av[1];
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(*str)
    {
        if ((*str >= 'a' && *str <= 'y') || (*str >= 'A' && *str <= 'Y'))
        {
            //car = *str + 1;
            *str +=1;
            write(1, str, 1);
        }
        else if (*str == 'z' ||*str == 'Z')
        {   
            car = *str - 25;
            write(1, &car, 1);
        }
        else 
            write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return(0);
}