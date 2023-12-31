#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("please enter a number: ");
    scanf("%d", &num);

    unsigned long total=1;

    if (num == 0 || num == 1)
        printf("Factorial is 1");
    else {
        for (int i=2; i <= num; i++)
        {
            total*=i;
        }
        if (total / 1000 > 1)
            printf("Factorial is %ld k", total/ 1000);
        //printf("Factorial is %ld", total);
    }

    return 0;
}
