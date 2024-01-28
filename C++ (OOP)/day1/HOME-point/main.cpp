#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    void print()
    {
        cout<< "(" << x << ", " << y << ")" << endl;
    }

    void setX(int _x)
    {
        x = _x;
    }
    int getX()
    {
        return x;
    }

    void setY(int _y)
    {
        y = _y;
    }
    int getY()
    {
        return y;
    }
};
int main()
{
    Point p;

    p.setX(4);
    p.setY(10);



    p.print();
    cout << "Hello world!" << endl;
    return 0;
}
