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
            cout<< real << "+" << img<<"i";//<<endl;
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
    int operator== (Complex& c)
    {
        return real == c.real && img == c.img;
    }
    int operator!= (Complex& c)
    {
        return !(*this == c);
    }
    Complex& operator+=(Complex& c)
    {
        real = real + c.real;
        img = img + c.img;
        return *this;
    }
    Complex& operator++()  // prefix ++ => c1 = ++c;
    {
        real++;
        return *this;
    }
    Complex operator++(int) // postfix ++ => c1 = c++;
    {
        Complex res=*this;
        real++;
        return res;
    }
    explicit operator int()
    {
        return real;
    }
    friend ostream& operator<<(ostream& os, const Complex& c);

//    ~Complex ()
//    {
//        cout<<"Object Terminated"<<endl;
//    }
};
    ostream& operator<<(ostream& os, const Complex& c)
    {
        if (c.img > 0)
            os << c.real << "+" << c.img<<"i";//<<endl;
        else if (c.img == 0 )
            os <<c.real;//<<endl;
        else
            os <<c.real<<c.img<<"i";//<<endl;
//        os << c.real << '/' << c.img << '/' <<endl;
        return os;
    }

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
    Complex c11(30,40);

    Complex c2(10, 20);
    Complex c21(10, 20);

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
    cout<<endl<<"Result of Operator overloading (==) add"<<endl;
    cout<<"=============================="<<endl;
    cout<<"is ";
    c1.print();
    cout<<" and ";
    c11.print();
    cout<<" not the same?\t"<< (c1 == c11 ? "True":"False");
    cout<<endl<<"Result of Operator overloading (!=) add"<<endl;
    cout<<"=============================="<<endl;
    cout<<"is ";
    c1.print();
    cout<<" and ";
    c2.print();
    cout<<" not the same?\t"<< (c1 == c2 ? "True":"False");
    cout<<endl<<"Result of Operator overloading (+=) add"<<endl;
    cout<<"=============================="<<endl;
//    cout<<"is ";
    c1.print();
    cout<<" += ";
    c2.print();
    cout<<" ==>\t";
    (c1+=c2).print();
    cout<<endl<<"Result of Operator overloading (++ prefix) add"<<endl;
    cout<<"=============================="<<endl;
//    cout<<"is ";
    cout<<" ++(";
    c1.print();
    cout<<")";
    cout<<" ==>\t";
    (++c1).print();
    cout<<endl<<"Result of Operator overloading (++ postfix) add"<<endl;
    cout<<"=============================="<<endl;
//    cout<<"is ";
    cout<<"(";
    c2.print();
    cout<<")++";
    cout<<" ==>\t";
    (c2++).print();
    cout<<endl<<"Result of Operator overloading (int)"<<endl;
    cout<<"=============================="<<endl;
//    cout<<"is ";
    cout<<"(int)(";
    c2.print();
    cout<<")";
    cout<<" ==>\t"<<(int)c2<<endl;
    cout<<"=============================="<<endl;
    cout<<"=============================="<<endl;
    cout<<c2;
    return 0;
}

Complex add(Complex c1, Complex c2)
{
    Complex res;
    res.setReal(c1.getReal() + c2.getReal());
    res.setImg(c1.getImg() + c2.getImg());
    return res;
}
