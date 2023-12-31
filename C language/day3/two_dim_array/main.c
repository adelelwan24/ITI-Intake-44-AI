#include <stdio.h>
#include <stdlib.h>
#define row 2
#define col 3

int main()
{
    int nums[row][col] = {0};

    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ; j++)
        {
            printf("Please enter the number in row %d and col %d: ", i, j);
            scanf("%d", &nums[i][j]);
        }
    }

    printf("\n=========================\n");

    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ; j++)
            printf("| %4d |", nums[i][j]);
        printf("\n");
    }


    printf("=========================\n");

    int sumRow[row]={0};
    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ; j++)
            sumRow[i]+=nums[i][j];
        printf("Sum of the row %d: %d \n", i, sumRow[i]);
    }


    printf("=========================\n");

    float avgCol[col]={0};
    for (int j=0; j < col ; j++)
    {
        for (int i=0; i < row ; i++)
            avgCol[j]+=nums[i][j];
        avgCol[j]/=row;
        printf("Avg of the col %d: %f \n", j, avgCol[j]);
    }


    printf("=========================\n");


    return 0;
}
