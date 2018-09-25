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
};

int main()
{
    Car mashinka;
    mashinka.setWeight(1300);
    cout<<mashinka.getWeight()<<endl;
    return 0;
}