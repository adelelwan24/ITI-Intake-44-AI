#include <stdio.h>
#include <stdlib.h>

int power(int x, int y);

int main()
{
    int x, y, pow;
    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    pow = power(x, y);
    printf("power is %d", pow);
    return 0;
}

int power(int x, int y)
{
    int total=1;
    for (int i=0; i < y; i++)
        total*=x;
    return total;
}
