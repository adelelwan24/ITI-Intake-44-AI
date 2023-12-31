#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter first number:");
    scanf("%d", &x);
    printf("Enter second number:");
    scanf("%d", &y);
    printf("x: %7d & y: %7d  before swap \n", x, y);
    swap(&x, &y);
    printf("x: %7d & y: %7d  after swap \n", x, y);
    return 0;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
