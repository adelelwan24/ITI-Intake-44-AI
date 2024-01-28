#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;
public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int _real, int _img)
    {
        real = _real;
        img = _img;
    }

    void setReal(int _real)
    {
        real = _real;
    }
    void setImg(int _img)
    {
        img = _img;
    }
    int getReal()
    {
        return real;
    }
    int getImg()
    {
        return img;
    }

    void print()
    {
        if (img > 0)
            cout<< real << "+" << img<<"i"<<endl;
        else if (img == 0 )
            cout<<real<<endl;
        else
            cout<<real<<img<<"i"<<endl;
    }
    Complex add(Complex c)
    {
        Complex res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
    }
    Complex operator+ (Complex const & c)
    {
        Complex res;
        res.real = c.real + real;
        res.img = c.img + img;
        return res;
    }
    Complex operator+ (int x)
    {
        Complex res;
        res.real = x + real;
        res.img = img;
        return res;
    }
//    ~Complex ()
//    {
//        cout<<"Object Terminated"<<endl;
//    }
};

Complex add(Complex c1, Complex c2);

//Complex operator+(int r, Complex & c)
//{
//	Complex res(r,0);
//	res.setReal(c.getReal() + res.getReal());
//	res.setImg(c.getImg() + res.getImg());
//	return  res;
//}
//

//Complex operator+(int r, Complex c)
//{
//	c.setReal(c.getReal() + r);
//	return  c;
//}


Complex operator+(int r, Complex c)
{
	return  c + r;            // Depend on Complex operator+ (int x)
}

int main()
{

    Complex c1(30, 40);
    Complex c2(10, 20);

    Complex res, res1;
    c1.print();
    cout<<endl<<"Result of the Member Function add"<<endl;
    res = c1.add(c2);
    res.print();
    cout<<endl<<"Result of Stand Alone Function add"<<endl;
    res = add(c1, c2);
    res.print();

    cout<<endl<<"Result of Operator overloading (+) add"<<endl;
    cout<<"=============================="<<endl;
    res1 = c1 + res;
    res1.print();
    res1 = res1 + 30;
    res1.print();
    res1 = 100 + res1;
    res1.print();
    return 0;
}

Complex add(Complex c1, Complex c2)
{
    Complex res;
    res.setReal(c1.getReal() + c2.getReal());
    res.setImg(c1.getImg() + c2.getImg());
    return res;
}
