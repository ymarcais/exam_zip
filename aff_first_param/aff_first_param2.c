#include<unistd.h>

int main(int ac, char **av)
{
    char *str = NULL;
    
    if(ac < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    str = av[1];
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return 0;
}