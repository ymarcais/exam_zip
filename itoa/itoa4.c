#include <unistd.h>
#include <stdlib.h>

int cont(unsigned nb, int sign)
{
    int size = 0;

    if (sign == - 1)
        size++;
    while(nb)
    {
        nb /= 10;
        size++;
    }
    return (size);
}

char conv(unsigned nb, int size, char *str)
{
    int i = size -1;
    str[size] = '\0';
    while(nb > 0)
    {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i--;
    }
    return (*str);
}

char *ft_itoa(int nbr)
{
    int size = 0;
    int sign = 0;
    int nb;
    char *str;

    if (nbr < 0)
        sign = -1;
    else    
        sign = 1;
    nb = sign * nbr;
    size = cont(nb, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    if (sign == -1)
    {
        str[0] = '-';
        conv(nb, size, str);
    }
    else
    {
        conv(nb, size, str);
    }    
    return(str);
}

#include <stdio.h>
int main(void)
{
    int d = -6;
    printf("%s\n", ft_itoa(d));
    d = 4582256;
    printf("%s\n", ft_itoa(d));
    return (0);
}