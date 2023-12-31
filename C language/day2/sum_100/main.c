#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int sum = 0;

    do
    {
        printf("Please enter a number: ");
        scanf("%d", &num);

        sum+=num;
    } while (sum <= 100);

    printf("sum is %d", sum);

    return 0;
}
