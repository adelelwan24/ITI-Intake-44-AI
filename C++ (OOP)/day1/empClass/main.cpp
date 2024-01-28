#include <iostream>
#include <string.h>
using namespace std;


class emp {
    int id;
    char name[20];
    int salary;
    public:
        void print()
        {
            cout<< id << ":" << name << ":" << salary << endl;
        };
        void setId(int _id)
        {
            if (_id >= 0)
                id = _id;
        }
        void setSalary(int _salary)
        {
            if (_salary >= 0)
                salary = _salary;
        }
        void setName(char* _name)
        {
            strcpy(name, _name);
        }
        int getId()
        {
            return id;
        }
        int getSalary()
        {
            return salary;
        }
        char* getName()
        {
            return name;
        }
};
int main()
{
    emp e;
    e.setId(12);
    e.setName("adel");
    e.setSalary(230000);

    e.print();
    cout<< e.getName();
    return 0;
}
