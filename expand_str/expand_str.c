/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:45:17 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/22 12:13:24 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char    *str;
    int     inside = 0;
    
    str = av[1];
    if (ac != 2)
    {
        write(1, "\n", 2);
            return (0);
    }
    while(*str)
    {
        if (inside)
        {
            if (*str == ' ' || *str == '\t' || *str == '\n')
            {
                write(1,"   ", 3);
                inside = 0;
            }
            else
            {
                write(1, str, 1);
            }
        }
        else
        {
            if (*str == ' ' || *str == '\t' || *str == '\n')
            {
               str++;
               continue; 
            }
            else
            {
                write(1, str, 1);
                inside = 1;
            }
        }
        str++;
    }
    write(1, "\n", 1);
    return (0);
}