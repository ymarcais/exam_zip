#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int count(unsigned int num, int sign)
{
    int i = 0;

    if (sign < 0)
        i++;
    while(num > 0)
    {
        num /= 10;
        i++;
    }
    return i;
}

char conv(unsigned int num, int size, char *str)
{
    str[size] = '\0';
    while(num > 0)
    {
        str[size - 1] = num % 10 + '0';
        num /= 10;
        size--;
    }
    return *str;
}

char	*ft_itoa(int nbr)
{
    unsigned int num = 0;
    int size = 0;
    int sign = 1;
    char *str = NULL;

    if (nbr < 0)
        sign = -1;
    num = nbr * sign;
    size = count(num, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return NULL;
    if (sign == -1)
        str[0] = '-';
    conv(num, size, str);
    return str;
}

int main(void)
{
    char *str = NULL;

    str = ft_itoa(-123);
    printf("%s", str);
    free(str);
    return 0;
}