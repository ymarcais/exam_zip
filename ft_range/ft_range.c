#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int *range = NULL;
    int size, i = 0;
    
    if (end > start)
    {
        size = end - start + 1;
        range = malloc(sizeof(int) * (size + 1));
        if (!range)
            return (NULL);
        while( end >= start)
        {
            range[i] = start;
            start++;
            i++;
        }
        range[size] ='\0';
    }
    else if (end == start)
    {
        range = malloc(sizeof(int) * 2);
        if (!range)
            return (NULL);
        range[0] = start;
        range[1] = '\0';
    }
    else
    {
        size = start - end + 1;
        range = malloc(sizeof(int) * (size + 1));
        if (!range)
            return (NULL);
        while( end <= start)
        {
            range[i] = start;
            start--;
            i++;
        }  
        //range[size] = '\0';
    }
    return (range);
}

int main(void)
{
    int *range;
    int i = 0;

    range = ft_range(-2, 3);
    while (i < 6)
    {
        printf("%d\n", range[i]);
        i++;
    }
    return (0);
}

    