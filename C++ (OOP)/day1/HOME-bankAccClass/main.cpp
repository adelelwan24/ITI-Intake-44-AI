#include <iostream>
#include <string.h>

using namespace std;

class BankAcc
{
    char clientName[40];
    int balance;
    char type[20];
public:
    print()
    {
        cout<< clientName << ":" << type << ":" << balance<< endl;
    }

    setClientName(char * _name)
    {
        strcpy(clientName, _name);
    }
    char* getClientName()
    {
        return clientName;
    }

    setBalance(int b)
    {
        balance = b;
    }
    int getBalance()
    {
        return balance;
    }
    setType(char* _type)
    {
        strcpy(type, _type);
    }
    char* getType()
    {
        return type;
    }

};

int main()
{
    BankAcc ba;

    ba.setClientName("ahmed aly");
    ba.setBalance(120);
    ba.setType("Depit");

    ba.print();

    return 0;
}
