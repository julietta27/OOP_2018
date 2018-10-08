#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

class Engine
{
	int VIN;
	public:
	    Engine(){}
	    Engine(int _v):VIN(_v){}
	    void setVIN(int _v){VIN=_v;}
	    int getVIN(){return VIN;}
};

// 1. copy constructor
class Car
{
    double fuel;
    Engine* engine;
    public:
        Car(int _v){engine = new Engine(_v);}
        void printInfo(){cout<<engine<<" "<<engine->getVIN()<<endl;}
        void setVIN(int _v){engine->setVIN(_v);}
};

int main()
{
  Car* mashinka [1000];
  mashinka[0] = new Car(111111);
  mashinka[1] = new Car(222222);
  Car ford(*mashinka[1]);
  mashinka[0]->printInfo();
  mashinka[1]->printInfo();
  mashinka[1]->setVIN(33);
  ford.printInfo(); // 33!
  return 0;
}