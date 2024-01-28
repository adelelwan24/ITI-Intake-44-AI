#include <iostream>

using namespace std;

class Stack
{
    int arr[5];
    int size;
    int tos;
public:
    Stack()
    {
        arr[5] = {0};
        size = 5;
        tos = 0;        // AKA for Top Of Stack
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
};

void viewContent(Stack s);

int main()
{
    Stack s1;
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

    viewContent(s1);
    return 0;
}

void viewContent(Stack s)
{
    if (s.isEmpty())
        cout<<"Stack is Empty"<<endl;
    else
    {
        int x=0;
        while (s.pop(&x))
        {
            cout<<x<<endl;
        };

    }
}
