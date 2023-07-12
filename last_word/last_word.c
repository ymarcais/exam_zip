#include<unistd.h>
#include<stdlib.h>

int ft_space(char c)
{
    return(c >= 9 && c<= 12) || c == 32;
}

int main(int ac, char **av)
{
    char *str = NULL;
    int i = 0;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    str = av[1];
    while(str[i])
        i++;
    i--;
    while(ft_space(str[i]))
        i--;
    while(i >= 0 && !ft_space(str[i]))
        i--;
    i++;
    while(str[i] && !ft_space(str[i]))
    {
        write(1, &str[i], 1);
        i++;
    }
    return 0;
}