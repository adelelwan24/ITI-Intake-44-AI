#include <stdio.h>
#include <stdlib.h>
#define size 5

struct emp
{
    int id;
    char name[10];
    int age;
    int salary;
    int overtime;
    int deduction;
};
int main()
{
    struct emp e[size];
    int tempId;
    short flag=0;

    for (int i=0; i < size; i++)
    {
        printf("Employee no %d info: \n", i);
        do
        {
            flag=0;
            printf("Enter employee id: ");
            scanf("%d", &tempId);
            for (int z=0; z <= i; z++)
                {
                    if (e[z].id == tempId)
                    {
                        printf("Employee id already exists.\n");
                        flag=1;
                        break;
                    }

                }
        } while (flag);

        e[i].id = tempId;

        printf("Enter employee name: ");
        scanf("%s", e[i].name);
        printf("Enter employee age: ");
        scanf("%d", &e[i].age);
        printf("Enter employee salary: ");
        scanf("%d", &e[i].salary);
        printf("Enter employee overtime: ");
        scanf("%d", &e[i].overtime);
        printf("Enter employee deduction: ");
        scanf("%d", &e[i].deduction);

    }


    for (int i=0; i < size; i++)
        printf("%-7d : %-7s : %-7d : %-7d\n", e[i].id, e[i].name, e[i].age, e[i].salary + e[i].overtime - e[i].deduction);
//    printf("Hello world!\n");
    return 0;
}
