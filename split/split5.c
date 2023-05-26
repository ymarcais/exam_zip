#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
    int i = 0, k = 0, j = 0;
    char **split;

    split = malloc(sizeof(char *) * 241);
    if (!split)
        return (NULL);
    while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
        i++;
    while(str[i])
    {
        j = 0;
        split[k] = malloc(sizeof(char ) * 4096);
        if (!split)
            return (NULL);
        while(str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
        {
            split[k][j++] = str[i++];
            
        }    
        while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        split[k][j] = '\0';
        k++;
        
    }
    split[k] = '\0';
    return(split);
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