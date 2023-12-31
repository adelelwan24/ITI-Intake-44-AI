#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim;
    printf("Enter array dim:");
    scanf("%d", &dim);

    int* ptr = (int*)malloc(dim * sizeof(int));
    for (int i=0; i < dim; i++)
    {
        printf("Enter the element no %d:", i);
        scanf("%d", &ptr[i]);
    }
    for (int i=0; i < dim; i++)
        printf("%5d \n", ptr[i]);

    //free allocation
    free(ptr);
    return 0;
}
