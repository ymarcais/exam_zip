#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char *rev_print(char *str)
{
    int     i = 0, j = 0;
    char    *mall;

    if(!str)
        return (NULL);
    while(str[i] != '\0')
        i++;
    mall = malloc(sizeof(char) * (i + 1));
    if (!mall)
        return  (NULL);
    mall[i] = '\0';
    i--;
    while (i > -1)
    {
        mall[j] = str[i];
        j++;
        i--;
    }
    return mall;
}

int main(void)
{
    char *reversed = rev_print("toto a la plage");
    // if (reversed != NULL)
    // {
        printf("test = %s\n", reversed);
        write(1, rev_print("toto a la plage"), 16);
        // free(reversed);
    // }
    // return 0;
}
