#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    int y;

    while(num != 0)
    {
        y = num%10;
        num = num/10;
        printf("%d", y);
    }

    return 0;
}
