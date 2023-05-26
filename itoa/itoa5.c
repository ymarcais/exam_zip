#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int cont(unsigned int nb, int sign)
{
    int size = 0;
    if (sign == -1)
        size++;
    while(nb)
    {
        nb /= 10;
        size++;
    }
    printf("size %d\n", size);
    return (size);
}

char    conv(unsigned int nb, char *str, int size)
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

char    *ft_itoa(int nbr)
{
    int size = 0, sign = 1, nb = 0;
    char *str;

    if (nbr < 0)
        sign = -1;
    nb = sign * nbr;
    size = cont(nb, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return(NULL);
    if (sign == -1)
    {
        str[0] = '-';
        conv(nb, str, size);
    }
    else
        conv(nb, str, size);    
    
    return(str);
}


int main(void)
{
    int d = -13;
    printf("%s\n", ft_itoa(d));
    return (0);
}