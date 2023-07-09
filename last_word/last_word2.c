#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char	*str = NULL;
	int		i = 0;

	if(ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	while(str[i] != '\0')
		i++;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i--;
	while((str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
		i--;
	i++;
	while(str[i] != '\0' && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}