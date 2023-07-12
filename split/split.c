/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:57:33 by ymarcais          #+#    #+#             */
/*   Updated: 2023/07/12 11:17:36 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int cw(char *str)
{
    int inside = 0, w = 0;
    char *tmp;

    tmp = str;
    while(*tmp)
    {
        if (inside)
        {    
            if (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
                inside = 0;
        }
        else
        {
            if (*tmp == ' ' || *tmp == '\t' || *tmp == '\n' )
            {
                tmp++;
                continue;
            }
            else
            {
                inside = 1;
                w++;    
            }
        }
        tmp++;
    }
    return (w);
}

int cc(char *str)
{
    char *tmp;
    int len = 0;
    
    tmp = str;
    while(*str && *tmp != '\n' && *tmp != '\t' && *tmp == ' ')
    {
        len++;
        str++;
    }    
    return (len);
}

char cpy(char *s1,char *s2,int len)
{
    int i = -1;
    
    while(++i < len)
    {
        s1[i] = s2[i];
        i++;        
    }
    s1[i] = '\0';
    return (*s1);    
}

char **ft_split(char *str)
{
    int k = 0, w = 0, len = 0;
    char **split;

    w = cw(str);
    split = malloc(sizeof(char *) * (w + 1));
    if (!split)
        return (NULL);
    while(*str)
    {
        while(*str && (*str == '\n' || *str == '\t' || *str == ' '))
            str++;       
        len = cc(str);
        split[k] = malloc(sizeof(char) * (len + 1));
        if (!split)
            return (NULL);        
        str += len;
        k++;
    }
    split[k] = '\0';
    return (split);
}

int		main(void)
{
	int i = 0;
	char **tab;
		
	tab = ft_split("bonjour je m'appelle Arthur");
	while (i < 4)
	{
		printf("string %d : %s\n", i, tab[i]);
		free(tab[i]);
        i++;
	}
    free (tab);
	return (0);
}