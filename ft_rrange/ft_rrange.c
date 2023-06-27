#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int size = 0, i = 0;
    int *range = NULL;

    if (end > start)
    {
        size = end - start + 1;
        range = malloc(sizeof(int) * (size + 1));
        if(!range)
            return (NULL);
        while(end >= start)
        {
            range[i] = end;
            end--;
            i++;
        }
        range[size] = '\0';
    }
    else if (start == end)
    {
        range = malloc(sizeof(int) * (size + 1));
        if(!range)
            return (NULL);
        range[0] = end;
        range[1] = '\0';
    }
    else 
    {
        size = start - end + 1;
        range = malloc(sizeof(int) * (size + 1));
        if(!range)
            return (NULL);
        while(  end <= start)
        {
            range[i] = end;
            end++;
            i++;
        }
        range[size] = '\0';
    }
    return (range);
}

int main (int ac, char **av)
{
    int size = 0;
    int start = 0;
    int end = 0;
    int i = 0;
    int *range;

    
    start = atoi(av[ac -2]);
    end = atoi(av[ac - 1]);
    if (start > end)
        size = start - end +1;
    else
        size = end - start + 1;
    range = ft_rrange(start, end);
    while( i < size)
    {
        printf("%d\n", range[i]);
        i++;
    }
    return (0);
}