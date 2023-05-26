#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
    int i = 0;
    
    while(*str)
    {
        i++;
        str++;
    }    
    return (i);
}

int main(int ac, char **av)
{
    char *str = av[ac -1];
    int i = 0;

    i = ft_strlen(str);
    printf("length = %d\n", i);
    return (0);
}