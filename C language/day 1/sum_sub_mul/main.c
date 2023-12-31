#include <stdio.h>

int main()
{
    int input1;
    int input2;

    int sum;
    int sub;
    int mul;

    scanf("%d", &input1);
    scanf("%d", &input2);

    sum = input1 + input2;
    sub = input1 - input2;
    mul = input1 * input2;

    printf("sum=%d \t sub=%d \t mul=%d \n\n", sum, sub, mul);
    printf("%d + %d = %d \n", input1, input2, sum);
    printf("%d - %d = %d \n", input1, input2, sub);
    printf("%d * %d = %d \n", input1, input2, mul);
    return 0;
}
