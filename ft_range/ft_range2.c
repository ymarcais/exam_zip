#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int     *ft_range(int start, int end)
{
    int *range = NULL;
    int size = 0, i = 0;
    
    size = start - end;
    if (size < 0)
    {
        size = -size + 1;
    }
    else    
        size += 1;
    range = malloc(sizeof(int) * (size + 1));
    if (!range)
        return NULL;
    if(start > end)
    {
        while(start >= end)
        {
            range[i] = start;
            start--;
            i++;
        }
    }
    else if (start == end)
        range[i] = start;
    else
    {
        while(start <= end)
        {
            range[i] = start;
            start++;
            i++;
        }
    }
    //range[size] = '\0';
    return (range);
}

int main(void)
{
    int *range = NULL;
    int i = 0;

    range = ft_range(-2, 4);
    while(i < 7)
    {
        printf("%d\n", range[i]);
        i++;
    }
    free(range);
    return (0);
    
}