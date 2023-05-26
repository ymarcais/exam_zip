/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:39:18 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/21 19:46:11 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_word(char *str)
{
    char    *tmp;
    int     w;
    int     inside = 0, i = -1;
    
    tmp = str;
    w = 0;
    while(tmp[++i])
    {    
        if  (inside)
        {
             if (*tmp == ' ' || *tmp == '\n' || *tmp == '\t')
             {
                inside = 0;
             }
        }
        else
        {
            if (*tmp == ' ' || *tmp == '\n' || *tmp == '\t')
                continue;
            else
            {
                inside = 1;
                w++;
            }
        }
    }
    return (w);
}

int count_char(char *str)
{
    int len = 0;

    while(str[len] && str[len] != ' ' && str[len] != '\n' && str[len] != '\t')
        len++;
    return (len);
}

char    cpy(char *s1, char *s2, int n)
{
    int i;

    i = -1;
    while(++i < n)
        s1[i] = s2[i];
    s1[i] = '\0';
    return (*s1);    
}

char    **ft_split(char *str)
{
    char    **split;
    int     i = 0;
    int     c;
    int     w;
    int     k;

    c = 0;
    w = 0;
    k = 0;
    w = count_word(str);
    split = malloc(sizeof (char*) * (w + 1));
    if (!split)
        return (NULL);
    while (str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
            i++;
        c = count_char(&str[i]);
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