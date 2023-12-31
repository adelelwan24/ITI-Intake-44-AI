#include <stdio.h>
#include <stdlib.h>

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
    struct emp e;

    printf("Enter employee id: ");
    scanf("%d", &e.id);
    printf("Enter employee name: ");
    scanf("%s", e.name);
    printf("Enter employee age: ");
    scanf("%d", &e.age);
    printf("Enter employee salary: ");
    scanf("%d", &e.salary);
    printf("Enter employee overtime: ");
    scanf("%d", &e.overtime);
    printf("Enter employee deduction: ");
    scanf("%d", &e.deduction);


    printf("%7d : %7s : %7d : %7d", e.id, e.name, e.age, e.salary + e.overtime - e.deduction);
    return 0;
}
