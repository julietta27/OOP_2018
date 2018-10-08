#include <iostream>
using std::cout;
using std::endl;

class Car
{
    double fuel;
    friend Car& setFuel(double _d, Car& c); //private!
    public:
    double getFuel(){return fuel;}
};

Car& setFuel(double _d, Car& c){c.fuel=_d; return c;} // no Car:: !

int main()
{
  Car c1;
  cout<<setFuel(20,c1).getFuel();
  return 0;
}