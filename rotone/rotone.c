#include<unistd.h>

int main(int ac, char **av)
{
    char    *str;

    str = av[1];
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(*str)
    {
        if((*str >='a' && *str <='y') || (*str > 'A' && *str <= 'Y'))
        {
            *str += 1;
            write(1, str, 1);
        }
        else if((*str =='z' || *str == 'Z'))
        {
            *str -= 25;
            write(1, str, 1);
        }
        else
            write(1, str, 1);
        str++;
    }
    return 0;
}