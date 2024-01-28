#include <iostream>

using namespace std;

class Queue
{
    int* arr;
    int size;
    int toq;
    int boq;
public:
    Queue() : Queue(5){}
    Queue(int _size)
    {
        toq = 0;
        boq = 0 ;
        size = _size;
        arr = new int[size];
    }
    Queue(Queue const & q)        // copy Construct
    {
        toq = q.toq;
        boq = q.boq;
        size = q.size;
        arr = new int[size];
        for (int i =0 ; i < toq ; i++)
        {
            arr[i] = q.arr[i];
        }
    }
    int isFull()
    {
        if (toq - boq == size )
            return 1;
        return 0;
    }
    int isEmpty()
    {
        if (toq == boq )
            return 1;
        return 0;
    }

    void circle(int & a)
    {
        if (a == size)
            a = 0;
    }
    int inQueue(int value)
    {
        if (isFull())
            return 0;
        circle(toq);
        arr[toq] = value;
        toq++;
        return 1;
    }
    int deQueue(int& value)
    {
        if (isEmpty())
            return 0;
        circle(boq);
        value = arr[boq];
        boq++;
        return 1;
    }
    int peak()
    {
        return arr[boq];
    }

    Queue operator+(Queue& q)
    {
        Queue res(size + q.size);
        res.toq = toq + q.toq -1;

        int i;
        for ( i=0; i < toq; i++)
        {
            res.arr[i] = arr[i];
        }
        for (int j=0; j < q.toq ; j++)
        {
            res.arr[i] = q.arr[j];
            i++;
        }
        return res;
    }

    Queue& operator=(Queue const& q)
    {
        toq = q.toq;
        size = q.size;
        delete [] arr;
        arr = new int[size];
        for (int i=0; i < q.toq; i++)
        {
            arr[i] = q.arr[i];
        }
        return *this;
    }
    ~Queue()
    {
        delete arr;
    }
};

void viewContent(Queue * q);

void sidePeak(Queue q)
{
    viewContent(&q);
}

int main()
{
    Queue q1(3);
    if (!q1.inQueue(10))
        cout<<"Queue is Full"<<endl;
    if (!q1.inQueue(13))
        cout<<"Queue is Full"<<endl;
    if (!q1.inQueue(16))
        cout<<"Queue is Full"<<endl;
    if (!q1.inQueue(50))
        cout<<"Queue is Full"<<endl;
//
    int x;
    sidePeak(q1);
    cout<<"========================"<<endl;
    q1.deQueue(x);
    viewContent(&q1);
    if (!q1.inQueue(100))
        cout<<"Queue is Full"<<endl;
    if (!q1.inQueue(10000))
        cout<<"Queue is Full"<<endl;
    cout<<"========================"<<endl;
//    q1.deQueue(x);
//    viewContent(&q1);

    Queue q2(5);
    Queue q3;
    if (!q2.inQueue(1))
        cout<<"Queue is Full"<<endl;
    if (!q2.inQueue(2))
        cout<<"Queue is Full"<<endl;
    if (!q2.inQueue(3))
        cout<<"Queue is Full"<<endl;
    if (!q2.inQueue(4))
        cout<<"Queue is Full"<<endl;

//    q3=q1=q2;
//    Queue s4 = (q1 + q2);
    q3= q1 + q2;
    cout<<endl<<"========================"<<endl;
    viewContent(&q3);
    cout<<"========================"<<endl;
    return 0;
}

void viewContent(Queue * q) // doesn't call copy construct but interact directly with the s reference. change outside too.
//void viewContent(Queue s) // call copy construct and if the default is used the any pointers point to the same location
{
    if (q->isEmpty())
        cout<<"Queue is Empty"<<endl;
    else
    {
        int x=0;
        while (q->deQueue(x))
        {
            cout<<x<<endl;
        };

    }
}
