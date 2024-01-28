#include <iostream>
#include <string.h>

using namespace std;

class Car
{
    char model[20];
    char color[20];
    int maxSpeed;
    int curSpeed;
public:
    print()
    {
        cout<< model << ":" << color << ":" << maxSpeed << ":" << curSpeed << endl;
    }

    setModel(char* _model)
    {
        strcpy(model, _model);
    }
    char* getModel()
    {
        return model;
    }

    setColor(char* _color)
    {
        strcpy(color, _color);
    }
    char* getColor()
    {
        return color;
    }

    setMaxSpeed(int _max)
    {
        maxSpeed = _max;
    }
    int getMaxSpeed()
    {
        return maxSpeed;
    }

    setCurSpeed(int _cur)
    {
        curSpeed = _cur;
    }
    int getCurSpeed()
    {
        return curSpeed;
    }

};
int main()
{
    Car c;

    c.setModel("Lambo");
    c.setColor("drak-red");
    c.setMaxSpeed(320);
    c.setCurSpeed(260);

    c.print();

    c.setCurSpeed(310);

    c.print();

    return 0;
}
