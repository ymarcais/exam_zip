/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:32:12 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/22 15:47:20 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char array[128] = {0};
    char    *s1;
    char    *s2;
    int     i = 0;

    s1 = av[1];
    s2 = av[2];
    while(s1[i] != '\0')
    {
        array[s1[i]] = 1;
        i++;
    }
    i = 0;
    while(s2[i] != "\0")
    {
        array[s2[i]] = 1;
        i++;
    }
    i = 0;
    while(*s1)
    {
        if (array[s1[i]] = 1)
        {
            array[s1[i]] = 0;
            write(1, s1[i], 1);
        }
        i++;
    }
    i = 0;
    while(*s2)
    {
        if (array[s2[i]] = 1)
        {
            array[s1[i]] = 0;
            write(1, s1[i], 1);
        }
        i++;
    }
    return (0);    
    
}