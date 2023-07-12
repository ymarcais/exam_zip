#include<unistd.h>
#include<stdio.h>

int main(int ac, char **av)
{
	char *str1 = NULL;
	char *str2 = NULL;
	int array[128] = {0};
	int i = 0;


	if(ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	str1= av[1];
	str2= av[2];
	while(str1[i] != '\0')
	{
		array[(int)(str1[i])] = 1;
		i++;
	}
	i = 0;
	while(str2[i])
	{
		array[(int)(str2[i])] = 1;
		i++;
	}
	i = 0;
	while(str1[i] != '\0')
	{
		if(array[(int)(str1[i])] == 1)
		{
			array[(int)(str1[i])] = 0;
			write(1, &str1[i], 1);
		}	
		i++;
	}
    i = 0;
	while(str2[i] != '\0')
	{
		if(array[(int)(str2[i])] == 1)
		{
			array[(int)(str2[i])] = 0;
			write(1, &str2[i], 1);
		}	
		i++;
	}
	write(1, "\n", 1);
	return 0;
}