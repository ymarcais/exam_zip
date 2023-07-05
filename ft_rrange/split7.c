#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

char    **ft_split(char *str)
{
    int i = 0, j = 0, k = 0;
    char **split = NULL;

    split = malloc(sizeof(char*) * 450);
    if (!split)
        return NULL;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
    while(str[i])
    {
        j = 0;
        split[k] = malloc(sizeof(char) * 5000);
        if(!split)
            return NULL;
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            split[k][j++] = str[i++];
        }
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        split[k][j] = '\0';
        k++;        
    }
    return split;
}

int main(void)
{
	char **tab;
	int i = 0;

	tab = ft_split(" bonjour je m'apelle arthur   ");
	while(i < 6)
	{
		printf("indice %d : %s\n", i, tab[i]);
		free(tab[i]);
		i++;		
	}
	free(tab);
	return 0;
}