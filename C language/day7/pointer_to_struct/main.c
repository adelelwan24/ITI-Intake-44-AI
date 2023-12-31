#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int id;
    char name[10];
    int age;
};

int main()
{
    struct emp e1;
    struct emp* pointer = &e1;

    printf("Enter id:");
    scanf("%d", &(*pointer).id);
    printf("Enter name:");
    scanf("%s", (*pointer).name);
    printf("Enter age:");
    scanf("%d", &pointer->age);

    printf("\nEmployee id : %d", pointer->id);
    printf("\nEmployee name : %s", pointer->name);
    printf("\nEmployee age : %d", (*pointer).age);

    return 0;
}
