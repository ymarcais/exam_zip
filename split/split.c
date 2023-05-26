/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:48:50 by ymarcais          #+#    #+#             */
/*   Updated: 2023/05/21 17:57:59 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int count_word(char *str)
{
    char    *tmp;
    int     nbr_wrd;

    tmp = str;
    nbr_wrd = 0;
    while(*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
        tmp++;
    if (*tmp != ' ' || *tmp != '\t' || *tmp == '\n')
        nbr_wrd = 1;
    while(*tmp)
    {
        if ((*tmp == ' ' || *tmp == '\t' || *tmp == '\n') &&  \
            (*(tmp + 1) != ' ' && *(tmp + 1) != '\t' && *(tmp + 1) != '\n'))
            nbr_wrd += 1;
        tmp++;            
    }
    return (nbr_wrd);
}

int count_char(char *str)
{
    char    *tmp;
    int     lengh;

    lengh = 0;
    tmp = str;
    while(*tmp != ' ' && *tmp != '\t' && *tmp != '\n' && *tmp != '\0')
    {
        tmp++;
        lengh++;
    }
    return (lengh);
}

char    cpy_(char *s1, char *s2, int n)
{
    int i;

    i = -1;
    while( ++i < n)
        s1[i] = s2[i];
    s1[i] = '\0';  
    return (*s1);
}

char    **ft_split(char *str)
{
    int c;
    int w;
    int k;
    char    **split;
    
    k = 0;
    c = 0;
    w = count_word(str);
    if(!(split = (char **)malloc(sizeof(char *) *(w + 1))))
        return (NULL);
    while(*str)
    {
        while(*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        c = count_char(str);

        // if ((split[k] = malloc))
            // I am here if split[k] is null
        split[k] = (char *)malloc(sizeof(char) * (c + 1));
        if (!split[k])
            return (NULL);
        cpy_(split[k], str, c);
        str = str + c;
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
/*int main(int ac, char **av)
{
    char **t ={0};
    int i;
    int j;
    
    i = 0;
    j = 0;
    t = ft_split(av[1]);
    while(t[j][j] != '\0')
    {
        j = 0;
        while(t[j][i] != '\n')
        {
            printf("%d", t[j][i]);
            j++;
        }
        i++;
   }
    return (0);
}*/