#include <iostream>
using namespace std;

class fraction
{
    int num;
    int den;
public:
    fraction(int n=0, int d=1)
    {
        num = n;
        if (d == 0)
            cout<<"the denumerator can't be zero";
        else
           den = d;
    }
    int getDen() {
        return den;
    }
    int getNum(){
        return num;
    }
    float getFloat(){
        return num / (float)den;
    }
    void print() {
        cout<<num<<"/"<<den<<endl;
    }
    fraction simplify()
    {
        if (num % den ==0)
          return fraction(num / den, 1);

        int n = num;
        int d = den;
        for (int i=den/2; i >2; i--)
        {
            if (d % i == 0 && n % i == 0)
            {
                d = d / i;
                n = n / i;
            }
        }
        return fraction(n, d);
    }


    fraction operator+( fraction& f)
    {
        int d = den * f.getDen();
        int n = num * f.getDen() + f.getNum() * den;
        return fraction(n, d).simplify();
    }
    fraction operator+( int f)
    {
        int d = den;
        int n = num  + f * den;
        return fraction(n, d).simplify();
    }
    fraction operator-( fraction& f)
    {
        int d = den * f.getDen();
        int n = num * f.getDen() - f.getNum() * den;
        return fraction(n, d).simplify();
    }
    fraction operator-( int f)
    {
        int d = den;
        int n = num  - f * den;
        return fraction(n, d).simplify();
    }
    fraction operator*( fraction& f)
    {
        int d = den * f.getDen();
        int n = num * f.getNum();
        return fraction(n, d).simplify();
    }
    fraction operator*( int f)
    {
        int d = den;
        int n = num  * f ;
        return fraction(n, d).simplify();
    }
        fraction operator/( fraction& f)
    {
        int d = den * f.getNum();
        int n = num * f.getDen();
        return fraction(n, d).simplify();
    }
    fraction operator/( int f)
    {
        int d = den * f;
        int n = num;
        return fraction(n, d).simplify();
    }
};
int main() {
    // Write C++ code here
    fraction f(5, 10);
    f.print();
    fraction s = f.simplify();
    s.print();
    fraction g(40*23, 20*23);
    g.simplify().print();
    s = f + g;
    s.print();
    s = f - g;
    s.print();
    s = f * g;
    s.print();
    s = f / g;
    s.print();

    return 0;
}
