#include<stdlib.h>
#include<stdio.h>

int     *ft_rrange(int start, int end)
{
    int sign = 1;
    int size = 0, i = 0;
    int *array = NULL;

    if (start > end)
        sign = -1;
    size = sign *(end - start);
    size++;
    array = malloc(sizeof(int) * (size));
    if(!array)
        return NULL;
    while(size > i)
    {
        array[i] = end - sign * i;
        i++;
    }
    return array;
}

int main(void)
{
    int *array = NULL;
    int i = 0;

    array = ft_rrange(3, -5);
    while(i < 9)
    {
        printf("%d\n", array[i]);
        i++;
    }
    free(array);
    return 0;
}