#include <stdio.h>
#include <stdlib.h>
#define size 4

int main()
{
    int nums[size] = {0};

    for (int i=0; i < size ; i++)
    {
        printf("Please enter number: ");
        scanf("%d", &nums[i]);
    }

    printf("\n=========================\n");

    for (int i=0; i < size ; i++)
        printf("| %-5d |", nums[i]);

    printf("\n=========================\n");

    int sum=0;
    for (int i=0; i < size ; i++)
        sum+=nums[i];
    printf("Sum of the array is : %d", sum);

    printf("\n=========================\n");

    int max=nums[0];
    for (int i=1; i < size ; i++)
        if (max < nums[i])
            max = nums[i];
    printf("Max of the array is : %d", max);

    printf("\n=========================\n");

    int min=nums[0];
    for (int i=1; i < size ; i++)
        if (min > nums[i])
            min = nums[i];
    printf("Min of the array is : %d", min);

    printf("\n=========================\n");

    int target;
    printf("Please enter the target: ");
    scanf("%d", &target);
    for (int i=0; i < size ; i++)
        if (target == nums[i])
            {
                printf("Target %d found at the index %d \n", target, i);
            }
    printf("\n=========================\n");

    return 0;
}
