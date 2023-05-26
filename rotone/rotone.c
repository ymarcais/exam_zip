/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:15:44 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/24 11:47:44 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char    *str = av[ac - 1];
    
    while(*str)
    {
        if ((*str >= 'a' && *str < 'z') || (*str >= 'A' && *str < 'Z'))
            *str += 1;
        else if (*str == 'z' || *str == 'Z')
            *str = *str - 25;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}