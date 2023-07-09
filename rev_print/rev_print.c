#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

char *rev_print(char *str)
{
    int     i = 0, j = 0;
    char    *mall;

    if(!str)
        return (NULL);
    while(str[i])
        i++;
    if(i == 0)
        return NULL;
    mall = malloc(sizeof(char) * (i + 1));
    if (!mall)
        return  (NULL);
    mall[i] = '\0';
    i--;
    while (i >= 0)
    {
        mall[j] = str[i];
        write(1, &mall[j], 1);
        j++;
        i--;
    }
    return mall;
}

int main(void)
{
    rev_print("Toto a la plage");
    write(1,"\n", 1);
    rev_print("  titi a la montagne");
    write(1,"\n", 1);
    rev_print("");
    write(1,"\n", 1);
    return (0);
}
