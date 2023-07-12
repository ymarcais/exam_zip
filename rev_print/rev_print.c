#include<unistd.h>
#include<stdlib.h>

char *rev_print(char *str)
{
    int len = 0, j = 0;
    char *rev = NULL;

    if(!*str)
        return NULL;
    while(str[len])
        len++;
    if (len == 0)
        return NULL;
    rev = malloc(sizeof(char) *(len + 1));
    if(!rev)
        return NULL;
    rev[len] = '\0';
    len--;
    while(len >= 0)
    {
        rev[j] = str[len];
        write(1, &str[len], 1);
        j++;
        len--;
    }
    return str;
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