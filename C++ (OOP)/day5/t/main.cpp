#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
	int x;
	int y;
public:
	Point()
	{
		x =0; y =0;
		cout<<"This is parameterless  point constructor";
	}
	Point(int _x, int _y)
	{
		x = _x; y = _y;
		cout<<"This is 2 parameters point constructor";
	}
	void setPoint(int _x, int _y)
	{
		x = _x; y = _y;
	}
	int getX(){ return x;}
	int getY(){ return y;}
	void print() {
	    cout<<"("<<x<<", "<< y<<")";
	    }
};

class Rect
{
	Point ul;
	Point lr;
public:
 //call Point default constructor first then continue to the code
	Rect()
    {
        cout<<"This is Parameterless rect constructor";
    }
    Rect(int x1, int y1, int x2, int y2)
    {
        ul.setPoint(x1, y1);
        lr.setPoint(x2, y2);
        cout<<"This is 4 Parameters rect constructor";
    }
    Point getUL() {return ul;};
    Point getLR() {return lr;};
    void draw()
    {
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};
class Line
{
	Point start;
	Point end;
public:
	Line(int s1, int s2, int e1, int e2)
	{
        start.setPoint(s1, s2);
        end.setPoint(e1, e2);
	}
	Line(Point x, Point y)
	{
	    start = x;
	    end = y;
	}
	void draw()
	{
	    line(start.getX(), start.getY(), end.getX(), end.getY());
	}


};

class Circle
{
    Point center;
    int rad;
public:
    Circle(int x, int y, int r):center(x,y)
    {
        rad = r;
    }
    Point getCenter() {return center;}
    int getRad() {return rad;}
    void setRad(int x) { rad = x;}
    void draw() {circle(center.getX(), center.getY(), rad);}
};

class Triangle
{
    Point x;
    Point y;
    Point z;
public:
    Triangle(int x1, int x2, int y1, int y2, int z1, int z2):x(x1, x2), y(y1, y2) , z(z1, z2)
    {

    }
    void draw()
    {
        Line l1(x,y);
        l1.draw();
        Line l2(x,z);
        l2.draw();
        Line l3(y,z);
        l3.draw();
    }
};

int main()
{
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    Rect r(50,50, 300, 400);
    r.getUL().print();
    r.getLR().print();
    r.draw();

    Line l(50, 50, 300, 400);
    l.draw();

    Circle c(50,50, 50);
    c.draw();

    Triangle t(50, 0, 0,50, 100, 50);
    t.draw();

    getch();
    closegraph();
    cout << "Hello world!" << endl;
    return 0;
};



