#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int cnt(int nb, int sign)
{
    int size = 0;
    
    while(nb)
    {
        nb /= 10;
        size++;
    }
    if (sign == -1)
        size++;
    return (size);
}

char conv( unsigned int nb, int size, char *str)
{
   int i = size - 1;

    str[size] = '\0';
    while(nb != 0)
    {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i--;
    }
    return (*str);
}

char	*ft_itoa(int nbr)
{
    int nb = 0;
    char *str;
    int size =0;
    int sign = 0;
    
    if (nbr < 0)
        sign = -1;
    else 
        sign = 1;
    nb = sign * nbr;      
    size = cnt(nb, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return(NULL);
    if (sign == - 1)
    {
        str[0] = '-';
        printf("size = %d\n", size);
        conv(nb, size, str);
    }
    else if (nbr == 0)
        str[0] = '0';
    else
        conv(nb, size, str);
    return (str);
}

/*int	main(void)
{
	int i = 0;
	int tab[6] = {-123456789, -2147483648, -42, 0, 42, 2147483647};

	while (i < 5)
    {
        printf("%s\n", ft_itoa(tab[i]));
        i++;
    }

	return 0;
}*/
/*
int	main(int ac, char **av)
{
    int nb;
    
    nb = atoi(av[ac - 1]);
    printf("%s", ft_itoa(nb));
	return (0);
}
*/
#include <stdio.h>
#include <limits.h>
 
int      main(void)
{
    int d = INT_MIN;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = -13;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = 0;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = 5;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = INT_MAX;
    printf("%d =? %s\n", d, ft_itoa(d));
}