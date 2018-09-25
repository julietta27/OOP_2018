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
        Car(const Car& that)
        {
            engine = new Engine();
        	*engine = *(that.engine);
        }
        // 2. copy assignment operator
        Car& operator=(const Car& that)
        {
            if (this != &that)
            {
                delete engine;
                engine = new Engine();
        	    *engine = *(that.engine);
            }
            return *this;
        }
        ~Car() {delete engine;}
        void printInfo(){cout<<engine<<" "<<engine->getVIN()<<endl;}
		void setVIN(int _v){engine->setVIN(_v);}
};

int main()
{
  Car* mashinka [2];
  mashinka[0] = new Car(111111);
  mashinka[1] = new Car(222222);
  Car ford(*mashinka[1]);
  mashinka[1]->setVIN(33);
  mashinka[0]->printInfo(); //111111
  mashinka[1]->printInfo(); //33
  ford.printInfo(); //222222
  delete mashinka[0];
  delete mashinka[1];
  ford.printInfo(); //222222
  return 0;
}