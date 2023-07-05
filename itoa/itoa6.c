#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int size_(unsigned int num, int sign)
{
    int size = 0;

    if (sign == - 1)
        size++;
    while(num > 0)
    {
        num /= 10;
        size++;
    }
    return size;
}

char    conv(unsigned int num, char *str, int size)
	{
	while(num > 0)
	{
		str[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
	return (*str);
	}

char	*ft_itoa(int nbr)
{
	int sign = 1, num = 0, size = 0;
	char *str = NULL;

	if (nbr < 0)
		sign = -1;
	num = nbr * sign;
	size = size_(num, sign);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return NULL;
	str[size] = '\0';
	if (sign == -1)
		str[0] = '-';
	conv(num, str, size);
	return (str);
}

int main(void)
{
    char *str = NULL;
    
    str = ft_itoa(-123);
    printf("%s", str);
    free(str);
    return 0;
}