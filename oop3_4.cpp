#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

struct CarNumber
{
    short num;// 777
    char letters [3]; // A MP
    short region; // 177
};

class Car
{
    private:
      double weight; // kg
      bool is_working; // working, or not
      string color; // color
      CarNumber number; // A777MP 177
    protected:
	  double fuel;
    public:
      void setWeight(double _d){weight=_d;};
      double getWeight(){return weight;};
      virtual void printInfo(){cout<<"Fuel "<<fuel<<endl;}
	  virtual void fuelUp()=0;
};

class Tank: public Car
{
    private:
      double gunCalibre;
    public:
      virtual void printInfo(){cout<<"Calibre "<<gunCalibre<<endl;
      Car::printInfo();}
      void setCalibre(double _d){gunCalibre=_d;}
	  virtual void fuelUp(){fuel=1500;}
};

class Volvo: public Car
{
	  void fuelUp(){fuel=200;}
};

class Fiat: public Car
{
	  void fuelUp(){fuel=170;}
};

int main()
{
  Car* mashinka [3];
  mashinka[0] = new Fiat();
  mashinka[1] = new Volvo();
  mashinka[2] = new Tank();
  dynamic_cast<Tank*>(mashinka[2])->setCalibre(7.62);
  for (int i=0; i<3; i++)
  {
    mashinka[i]->fuelUp();
    mashinka[i]->printInfo();
  }
  return 0;
}