#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int size;
    int tos;
public:
    Stack()
    {
        tos = 0;        // AKA for Top Of Stack
        size = 5;
        arr = new int[size];
    }
    Stack(int _size)
    {
        tos = 0;        // AKA for Top Of Stack
        size = _size;
        arr = new int[size];
    }
    Stack(Stack & s)        // copy Construct
    {
        tos = s.tos;
        size = s.size;
        // arr = s.arr    => default behavior
        arr = new int[size];
        for (int i =0 ; i < tos ; i++)
        {
            arr[i] = s.arr[i];
        }
    }
    int isFull()
    {
        if (tos == size)
            return 1;
        return 0;
    }
    int isEmpty()
    {
        if (tos == 0)
            return 1;
        return 0;
    }

    int push(int value)
    {
        if (isFull())
            return 0;
        arr[tos] = value;
        tos++;
        return 1;
    }
    int pop(int* value)
    {
        if (isEmpty())
            return 0;
        tos--;
        *value = arr[tos];
        return 1;
    }
    ~Stack()
    {
        delete arr;
    }
};

void viewContent(Stack * s);

int main()
{
    Stack s1(3);
    if (!s1.push(10))
        cout<<"Stack is Full"<<endl;
    if (!s1.push(13))
        cout<<"Stack is Full"<<endl;
    if (!s1.push(16))
        cout<<"Stack is Full"<<endl;
    if (!s1.push(50))
        cout<<"Stack is Full"<<endl;
    if (!s1.push(100))
        cout<<"Stack is Full"<<endl;
    if (!s1.push(10000))
        cout<<"Stack is Full"<<endl;

    viewContent(&s1);
    cout<<endl<<"========================"<<endl;
    viewContent(&s1);
    return 0;
}

void viewContent(Stack * s) // doesn't call copy construct but interact directly with the s reference. change outside too.
//void viewContent(Stack s) // call copy construct and if the default is used the any pointers point to the same location
{
    if (s->isEmpty())
        cout<<"Stack is Empty"<<endl;
    else
    {
        int x=0;
        while (s->pop(&x))
        {
            cout<<x<<endl;
        };

    }
}
