#include <iostream>
#include <math.h>
using namespace std;

class EquilateralTriangle;

class Triangle {
    float a,b,c;
    float p(){return (a+b+c)/2.0f;}
  public:
    float area ()
      {return sqrt(p()*(p()-a)*(p()-b)*(p()-c));}
    void fromEquilateral (EquilateralTriangle obj);
};

class EquilateralTriangle {
  friend class Triangle;
  private:
    float side;
  public:
    EquilateralTriangle (float _s) : side(_s) {}
};

void Triangle::fromEquilateral (EquilateralTriangle obj) {
  a = obj.side;
  b = obj.side;
  c = obj.side;
}
  
int main () {
  Triangle tr1;
  EquilateralTriangle tr2(10);
  tr1.fromEquilateral(tr2);
  cout << tr1.area();
  return 0;
}