/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:11:45 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/19 10:40:14 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int count_burn(char *str, char c, int i)
{
    int j;
    int k;
        
    j = 0;
    k = 0;
    while( k <= i)
    {
        if (str[k] == c)
            j++;
        k++;
    }
    return (j);
}

int count_char(char *str, char c)
{
    int i;
    
    i = 0;
    while(*str)
    {
        if (*str == c)
            i++;
        str++;
    }
    return (i);
}

int main(int ac, char **av)
{
    char    *str1;
    char    *str2;
    int     nb1;
    int     nb2;
    int     i;
    int     nbburn;
    
    i = 0;
    str1 = av[1];
    str2 = av[2];
    nb1 = 0;
    nb2 = 0;
    nbburn = 0;
    while(*str1)
    {
        nb1 = count_char(av[1], *str1);
        nb2 = count_char(av[2], *str2);
        nbburn = count_burn(av[1], *str1, i);
        if (nb1 <= nb2)
            write(1, str1, 1);
        if (nb1 > nb2)
            if (nbburn > nb2)
                ;
            else
            write(1, str1, 1);
        str1++;
        i++;
    }
    write(1, "\n", 1);
    return (0);    
}