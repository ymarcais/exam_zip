#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
    char **split;
    int k = 0, i = 0, j = 0;

    split = malloc(sizeof(char*) * 450);
    if (!split)
        return (NULL);
    while(*str == ' ' || *str == '\n' || *str == '\t')
        str++;
    while(str[i])
    {
        j = 0;
        split[k] = malloc(sizeof(char) * 5000);
        if (!str[k])
            return(NULL);
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            split[k][j++] = str[i++];
        while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            i++;
        split[k][j] = '\0';
        k++;
    }
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