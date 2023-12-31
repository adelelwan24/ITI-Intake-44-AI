#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    int half;
    int flag;

    for (int j=2; j <=num; j++)
    {
        half = j /2 ;
        flag = 1;
        for (int i=2; i <= half; i++)
        {
            if (j % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            //printf("%d is a prime number", j);
            printf("%d, ", j);
    }


    return 0;
}
