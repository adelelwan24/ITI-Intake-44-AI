#include <iostream>
#include <string.h>

using namespace std;


class Person
{
    int id;
    int age;
    char* name;
public:
    Person(){
    id = 0; age = 1; strcpy(name, "no body");}
    Person(int _id, int _age, char* _name){
    id = _id; age = _age; strcpy(name, _name);}
    void print(){
    cout<<id<<":"<<name<<":"<<age;}
    void setId(int _id) {id = _id;}
    void setName(char* _name) {strcpy(name, _name);}
    void setAge(int _age) {age = _age;}
    int getId() {return id;}
    int getAge() {return age;}
    char* getName() {return name;}

};

class Student:public Person
{
    char grade;
public:
    Student()
    {
        grade = 'A';
    };
    void setGrade(char _g) {grade = _g;}
    char getGrade() {return grade;}

    void print()
    {
        Person::print();
        cout<<":"<<grade;
    }
};

class Employee:public Person
{
    float salary;
public:
    void setSalary(int s) {salary = s;}
    int getSalary() {return salary;}
    void print()
    {
        Person::print();
        cout<<":"<<salary;
    }

};
int main()
{
    Student s;
    s.print();
    return 0;
}
