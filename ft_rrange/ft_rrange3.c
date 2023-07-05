#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int     *ft_rrange(int start, int end)
{
    int sign = 1;
    int size  = 0;
    int i = 0;
    int *range = NULL;

    size = end - start;
    if (size < 0)
        sign = -1;
    size *= sign;
    size++;
    range = malloc(sizeof(int) * (size));
    if (!range)
        return NULL;
    while(size > i)
    {
        range[i] = start + sign * i;
        i++;
    }
    return (range);
}

int main (void)
{
    int *range = NULL;
    int i = 0;

    range = ft_rrange(2, -5);
    while(i < 8)
    {
        printf("%d\n", range[i]);
        i++;
    }
    free(range);
    return 0;
}