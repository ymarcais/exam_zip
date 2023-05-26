/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:01 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/19 18:01:17 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_write(char *str, int array[])
{
        while(*str)
        {
            if (array[*str] == 1)
            {
                array[*str] = 0;
                write(1, str, 1);
            }
            str++;
        }
}

void    array_(char *str1, char *str2)
{
    int   array[128] = {0};
    char    *tmp;

    tmp = str1;
    while (*tmp)
    {
        array[*tmp] = 1;
        tmp++;
    }
    tmp = str2;
    while (*tmp)
    {
        array[*tmp] = 1;
        tmp++;
    }
    ft_write(str1, array);
    ft_write(str2, array);
}

int main(int ac, char **av)
{
    if (ac != 3)
        write(1, "\n", 1);
    array_(av[1], av[2]);
    write(1, "\n", 1);
}