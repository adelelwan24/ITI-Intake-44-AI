#include <iostream>
#include <string.h>
using namespace std;


struct emp {
    int id;
    char name[20];
    int salary;
    print()
    {
        cout<< id << ":" << name << ":" << salary << endl;
    }
};
int main()
{
    emp e;
    e.id = 12;
    strcpy(e.name, "adel");
    e.salary = 230000;

    e.print();
    return 0;
}
