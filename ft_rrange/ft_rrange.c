#include<stdlib.h>
#include<stdio.h>

int     *ft_rrange(int start, int end)
{
    int sign = 1;
    int *array = NULL;
    int i = 0, size = 0;

    if(start > end)
        sign = -1;
    size = sign *(end - start);
    size++;
    array = malloc(sizeof(int) * size);
    if(!array)
        return NULL;
    while(i <= size)
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
