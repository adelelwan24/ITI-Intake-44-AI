#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Enter rows:");
    scanf("%d", &rows);
    printf("Enter cols:");
    scanf("%d", &cols);

    int** arr = (int**)malloc(rows * sizeof(int*));

    for (int i=0; i < rows; i++)
        arr[i] = (int*)malloc(cols * sizeof(int));

    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            printf("Enter the element no[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }


    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            printf("%-5d ", arr[i][j]);
        }
        printf("\n");
    }

    // free allocation
    for (int i=0; i < rows; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
