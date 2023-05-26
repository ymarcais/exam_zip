/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:48 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/22 13:32:31 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_size(unsigned int nb, int sign)
{
    int size = 0;

    while(nb > 0)
    {
        nb /= 10;
        size++;
    }
    if (sign == -1)
        size++;
    return (size);
}

char    conv(char *str, unsigned int nb, int size)
{
    int i = 0;
    
    while(i - 1 < 0)
    {
        str[i] = nb % 10 + '0';
        nb /= 10;    
    }    
}

char    *ft_itoa(int nbr)
{
    unsigned int nb = 0;
    int sign = 1;
    int size = 0;
    char    *str = NULL;

    if (nbr < 0)
        sign = -1;
    nb = sign * nbr;
    size = ft_size(nb, sign);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
   str[size] = '\0';
   if (size = -1)
   {
    
    str[0] = '-';
    conv(str, nb, size);
   }
   else
   conv(str, nb, size);
   return (str);
}