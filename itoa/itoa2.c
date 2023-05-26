/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:14 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/24 14:54:34 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int cs(unsigned int nb, int sign)
{
    int	size = 0;

	if (nb == 0)
		return 1;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	if (sign == -1)
		size++;
    return size;
}

char conv(unsigned int nb, int size, char *str)
{
    int i = size -1;
    
    while(i > 0)
    {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i--;
    }
}

char    *ft_itoa(int nbr)
{
    int size = 0;
    unsigned int nb = 0;
    int sign = 1;
    char *str = NULL;

    
    if(nbr < 0)
        sign = -1;
    
    nb = sign * nbr;
    size = cs(nb, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    str[size] = '\0';
    
    if (sign == -1)
    {
            str[0] = '-';
        conv(nb, size, str);
    }
    else
       conv(nb, size, str);
    return str;
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return 1;

	int		nb = atoi(argv[1]);
	char	*str = ft_itoa(nb);

	printf("%s\n", str);
	free(str);
	return 0;
}
