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
    public:
      void setWeight(double _d){weight=_d;};
      double getWeight(){return weight;};
      virtual void printInfo(){cout<<"Weight "<<weight<<endl;}
};

class Tank: public Car
{
    private:
      double gunCalibre;
    public:
      virtual void printInfo(){cout<<"Calibre "<<gunCalibre<<endl;
      Car::printInfo();}
      void setCalibre(double _d){gunCalibre=_d;}
};

int main()
{
    Car* mashinka = new Tank();
    mashinka->setWeight(1000);
    dynamic_cast<Tank *> (mashinka)->setCalibre(7.62);
    mashinka->printInfo();
    return 0;
}