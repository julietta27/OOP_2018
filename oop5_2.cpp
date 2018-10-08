// https://stackoverflow.com/a/12142943
#include <iostream>
using namespace std;

class A
{
public:
    virtual void f() const { std::cout << "base"; }
};
class B: public A
{
public:
    virtual void f() const { std::cout << "derived"; }
};

std::ostream& operator<<(std::ostream& os, const A& a )
{
     a.f();
     return os;
}

int main()
{
    B b;
    std::cout << b << std::endl;

    return 0;
}