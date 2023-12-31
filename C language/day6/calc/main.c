#include <stdio.h>
#include <stdlib.h>

struct calc
{
    int sum;
    int sub;
    int mul;
};
void calcPointer(int x, int y, int* sum, int* sub, int* mul);
struct calc calcStruct(int x, int y, struct calc c);

int main()
{
    int x,y, sum=0, sub=0, mul=1;
    struct calc results;
    printf("Enter first number:");
    scanf("%d", &x);
    printf("Enter second number:");
    scanf("%d", &y);

    printf("sum: %7d & sub: %7d & mul: %7d before \n", sum, sub, mul);
    calcPointer(x, y, &sum, &sub, &mul);
    printf("sum: %7d & sub: %7d & mul: %7d after calcPointer \n", sum, sub, mul);
    results = calcStruct(x, y, results);
    printf("sum: %7d & sub: %7d & mul: %7d after calcSruct \n", results.sum, results.sub, results.mul);

    return 0;
}

void calcPointer(int x, int y, int* sum, int* sub, int* mul)
{
    *sum = x + y;
    *sub = x - y;
    *mul = x * y;
}

struct calc calcStruct(int x, int y, struct calc c)
{
    c.sum = x + y;
    c.sub = x - y;
    c.mul = x * y;
    return c;
}
