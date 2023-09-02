#include<stdlib.h>
#include<stdio.h>

int size_(unsigned int num, int sign)
{
    int size = 0;

    if(sign == -1)
        size++;
    while( num > 0)
    {
        num /= 10;
        size++;
    }
    return size;
}

char    conv(unsigned int num, char *str, int size)
{
    int i = 0;

    i = size - 1;
    while(num > 0)
    {
        str[i] = num % 10 + '0';
        num /= 10;
        i--;
    }
    return *str;
}

char	*ft_itoa(int nbr)
{
    unsigned num = 0;
    int size = 0;
    int sign = 1;
    char *str = NULL;

    if (nbr < 0)
        sign = -1;
    num = sign * nbr;
    size = size_(num, sign);
    str = malloc(sizeof(char) * (size + 1));
    if(!str)
        return NULL;
    str[size] = '\0';
    if (sign == -1)
        str[0] = '-';
    conv(num, str, size);
    return str;
}

int main(void)
{
    char *str = NULL;
    
    str = ft_itoa(-246);
    printf("%s", str);
    return (0);
}
