/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:52:04 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/19 11:11:18 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

void    array_(char *str1, char *str2)
{
   char array[128] = {0};
   int  i;

   while(*str2)
   {
        array[*str2] = 1;
        str2++; 
   }
   while(*str1)
   {
        if (array[*str1] >= 1)
        {
            array[*str1] -= 1;
            write(1, str1, 1);
        }
        str1++;
   }
    
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        array_(av[1], av[2]);
    }
    write(1,"\n", 1);
    return (0);
}