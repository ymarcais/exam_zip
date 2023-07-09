#include<unistd.h>

void rec(int num)
{
    if (num > 9)
        rec(num / 10);
    write(1, &"0123456789"[num % 10], 1);
}

int main(void)
{
    int num = 1;

    while( num < 101)
    {
        if (num % 4 == 0 && num % 7 == 0)
            write(1, "fizzbuzz", 8);
        else if ( num % 4 == 0)
            write(1, "fizz", 4);
        else if (num % 7 == 0)
            write(1, "buzz", 4);
        else 
            rec(num);
        write(1, "\n", 1);
        num++;
    }
    return 0;
}