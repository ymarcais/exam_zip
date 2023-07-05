#include<unistd.h>

int	ft_space(char c)
{
	return (c >= 9 && c<= 13) || c == 32;
}

int main(int ac, char **av)
{
	int len = 0;
	char *str = NULL;

	str = av[1];
	if (ac == 2)
	{
		while(*str && ft_space(*str))
			str++;
		while(str[len])
			len++;
		while(len && ft_space(str[len - 1]))
		{
			str[len - 1] = '\0';
			len--;
		}
		while(*str)
		{
			if(ft_space(*str))
			{
				if(!ft_space(*(str + 1)))
					write(1, "   ", 3);
			}
			else
				write(1, str, 1);
			str++;
		}		
	}
	write(1, "mmm\n", 4);
	return 0;
}

