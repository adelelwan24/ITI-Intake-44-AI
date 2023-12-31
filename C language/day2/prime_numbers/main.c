#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    int half = num /2;

    for (int i=2; i <= half; i++)
    {
        if (num % i == 0)
        {
            printf("%d is not a prime number", num);
            return 0;
        }
    }
    printf("%d is a prime number", num);

    return 0;
}
