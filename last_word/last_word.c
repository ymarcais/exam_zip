#include<unistd.h>
#include<stdio.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str;

    str = av[1];
    if(ac != 2 || str == NULL)
    {
        write(1, "\n", 1);
    }
    while(str[i] != '\0')
        i++;
    i--;
    while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        i--;
    while(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        i--;
    i++;
    while(str[i] != '\0' && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}