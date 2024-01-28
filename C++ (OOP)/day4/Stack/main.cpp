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
    Stack(Stack const & s)        // copy Construct
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

    Stack operator+(Stack& s)
    {
        Stack res;
        res.tos = tos + s.tos -1;
        res.size = size + s.size;
        delete [] res.arr;
        res.arr = new int[res.size];

        int i;
        for ( i=0; i < tos; i++)
        {
            res.arr[i] = arr[i];
        }
        for (int j=0; j < s.tos ; j++)
        {
            res.arr[i] = s.arr[j];
            i++;
        }
        return res;
    }

    Stack& operator=(Stack const& s)
    {
        tos = s.tos;
        size = s.size;
        delete [] arr;
        arr = new int[size];
        for (int i=0; i < s.tos; i++)
        {
            arr[i] = s.arr[i];
        }
        return *this;
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

//    viewContent(&s1);

    Stack s2(5);
    Stack s3;
    if (!s2.push(1))
        cout<<"Stack is Full"<<endl;
    if (!s2.push(2))
        cout<<"Stack is Full"<<endl;
    if (!s2.push(3))
        cout<<"Stack is Full"<<endl;
    if (!s2.push(4))
        cout<<"Stack is Full"<<endl;

//    s3=s1=s2;
//    Stack s4 = (s1 + s2);
    s3= s1 + s2;
    cout<<endl<<"========================"<<endl;
    viewContent(&s3);
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
