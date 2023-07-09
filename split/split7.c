#include<stdlib.h>
#include<stdio.h>

char    **ft_split(char *str)
{
    int j = 0, k = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * 500);
    if(!tab)
        return NULL;
    while(*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    while(*str)
    {
        j = 0;
        tab[k] = malloc(sizeof(char) * 5000);
        if(!tab[k])
            return NULL;
        while(*str && (*str != ' ' && *str != '\t' && *str != '\n'))
        {
            tab[k][j++] = *str++;;
        }
        tab[k][j] = '\0';
        while(*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        k++;     
    }
    return tab;
}

int main(void)
{
    char **tab = NULL;
    int i = 0;

    tab = ft_split("123456789 a la palge   ");
    while (i < 5)
    {
        printf("%s\n", tab[i]);
        //free(tab[i]);
        i++;
    }
    free(tab);
    return 0;
}