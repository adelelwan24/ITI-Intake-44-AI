#include <iostream>
#include <string.h>

using namespace std;
class String
{
    char* arr;
public:
    String()
    {
        arr = new char[1];
    }
    String(char* a)
    {
        int count=0;
        int i=0;
        while (a[i] != '\0')
        {
            ++i;
            ++count;
        }
        ++count;
        arr = new char[count] ;
//        for (int i=0; i < count; ++i)
//            arr[i] = a[i];
        strcpy(arr, a);

    }
    String (const String& s)
    {
        int sizes = s.len() +1;
        arr = new char[sizes];
        for (int i=0; i < sizes; ++i)
            arr[i] = s.arr[i];
    }
////////////////////// #########################################
    int len() const
    {
        int count=0;
        int i=0;
        while (arr[i] != '\0')
        {
            ++i;
            ++count;
        }
        return count;
    }
    String operator+(String& c)
    {
        int nsize = c.len() + this->len();
        char* narr = new char[nsize + 1];
        strcpy(narr, arr);
        strcat(narr, c.arr);
        String s(narr);
        return s;
    }
    String operator+(char* c)
    {
        int nsize = strlen(c) + this->len();
        char* narr = new char[nsize + 1];
        strcpy(narr, arr);
        strcat(narr, c);
        String s = narr;
        return s;
    }
    String& operator=(String s)
    {
        int sizes = s.len() +1;
        delete [] arr;
        arr = new char[sizes];
        for (int i=0; i < sizes; ++i)
            arr[i] = s.arr[i];
        return *this;
    }
    String& operator=(char* c)
    {
        int nsize = (int)strlen(c) + 1;
        delete [] arr;
        arr = new char[nsize];
        strcpy(arr, c);
        return *this;
    }
    void concat(String& s)
    {
        *this = *this + s;
    }
    friend istream& operator>> (istream& is,  String& c);
    friend ostream& operator<<(ostream& os,  String& c);
    ~String()
    {
        delete [] arr;
    }
};
istream& operator>> (istream& is,  String& c)
    {
        is >>c.arr;
        return is;
    }
ostream& operator<<(ostream& os,  String& c)
    {
        int y = c.len();
        for (int i =0; i < y; ++i)
            os <<c.arr[i];
        return os;
    }
int main()
{
    String a = "hello"; cout << a <<"\t"<< a.len()<< endl;
    String b = " World!"; cout << b <<"\t"<< b.len()<< endl;

    String x = a;
    a = a;
    String c = a + b; cout<< c<<"\t"<< c.len() << endl;

    String d;
    d = "wow nice to meet you";
    c = c + d; cout<< c<<"\t"<< c.len() << endl;
    c = a  + " Adel!"; cout<< c<<"\t"<< c.len() << endl;
    String e = a;
    e.concat(b);
    cout<< e<<"\t"<< e.len() << endl;

    return 0;
}
