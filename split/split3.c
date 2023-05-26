/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:25:25 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/21 20:39:06 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int cw(char *str)
{
    int inside = 0, w = 0;
    char *tmp;

    tmp = str;
    while(*tmp)
    {
        if (inside)
        {    
            if (*tmp == ' ' || *tmp == '\t' || *tmp == '\n' )
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
    int len = 0;
    char    *tmp;

    tmp = str;
    while(*tmp && *tmp != ' ' && *tmp != '\t' && *tmp != '\n' )
    {
        len++;
        tmp++;
    }
    return (len);    
}

char cpy(char *s1, char *s2, int len)
{
    int i;

    i = -1;
    while(++i < len)
        s1[i] = s2[i];
    s1[i] = '\0';
    return (*s1);    
}

char  **ft_split(char *str)
{
    char    **split;
    int     i = 0;
    int     c;
    int     w;
    int     k;

    c = 0;
    w = 0;
    k = 0;
    w = cw(str);
    split = malloc(sizeof (char*) * (w + 1));
    if (!split)
        return (NULL);
    while (str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
            i++;
        c = cc(&str[i]);
        split[k] = malloc(sizeof(char) * (c + 1));
        if (!split[k])
            return (NULL);
        cpy(split[k], &str[i], c);
        i += c;
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