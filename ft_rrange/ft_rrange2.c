#include<stdlib.h>
#include<stdio.h>

int     *ft_rrange(int start, int end)
{
    int sign = 1;
    int i = 0, size = 0;
    int *range = NULL;

    if (start > end)
        sign = -1;
    size = (end - start) * sign;
    size++;
    range = malloc(sizeof(int) * size);
    if (!range)
        return 0;
    while(size >= i)
    {
        range[i] = end - sign * i;
        i++;
    }
    return range;
}

int main(void)
{
    int i = 0;
    int *range = NULL;

    range = ft_rrange(-2, 5);
    while(i < 8)
    {
        printf("%d\n", range[i]);
        i++;
    }
    free(range);
    return 0;
}