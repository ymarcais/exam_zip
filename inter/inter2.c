#include <unistd.h>

int main(int ac, char **av)
{
    char *s1;
    char   *s2;
    int array[128] = {0};
    int i = 0;

    if (ac != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    s1 = av[1];
    s2 = av[2];
    while(s2[i] != '\0')
    {
        array[(int)s2[i]] = 1;
        i++;
    }
    i = 0;
    while(*s1)
    {
        if(array[(int)*s1] != 0)
        {
            array[(int)s1[i]] -= 1;
            write(1, &s1[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
