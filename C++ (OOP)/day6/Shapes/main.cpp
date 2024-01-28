#include <iostream>

using namespace std;

class Shape
{
protected:
    int dim1;
    int dim2;
public:
    Shape(){ dim1 = dim2 =1;}
    Shape(int dim) { dim1 = dim2 =dim;}
    Shape(int d1, int d2)
    {
        dim1 = d1;
        dim2 = d2;
    }
    void print(){cout<<"("<<dim1<<", "<<dim2<<")";}
    void setDim1(int dim) {dim1 = dim;}
    void setDim2(int dim) {dim2 = dim;}
    int getDim1() {return dim1;}
    int getDim2() {return dim2;}
};

class Rect :public Shape
{
public:
    void print() {Shape::print();cout<<" area="<<area()<<endl;}
    int area(){ return dim1 * dim2;}
};

class Square :protected Shape //parent attributes can only be accessed from the child class not from outside
{
public:
    Square():Shape(1){}
    Square(int dim):Shape(dim) {}
    void print() {Shape::print();cout<<" area="<<area()<<endl;}
    int area(){ return dim1 * dim2;}
    void setDim1(int dim){ dim1 = dim2 =dim;}
    void setDim2(int dim) {dim1 = dim2 = dim;}
};

class Triangle : public Shape
{
public:
    void print() {Shape::print();cout<<" area="<<area()<<endl;}
    float area() {return .5 * dim1 * dim2;}
};
class Circle : public Shape  //parent attributes can only be accessed from the child class not from outside
{
public:
    Circle():Shape(1){}
    Circle(int dim):Shape(dim){}
    void print() {Shape::print();cout<<" area="<<area()<<endl;}
    float area() {return 3.14 * dim1 * dim2;}
    void setDim1(int dim){ dim1 = dim2 =dim;}
    void setDim2(int dim) {dim1 = dim2 = dim;}
};
int main()
{
    Circle c;
    Rect r;
    Square s;
    Triangle t;

    c.print();
//    cout<<c.area()<<endl;

    r.print();
//    cout<<r.area()<<endl;

    s.print();
//    cout<<r.area()<<endl;

    t.print();
//    cout<<t.area()<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
