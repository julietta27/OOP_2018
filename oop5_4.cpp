#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    virtual string f() = 0;
};
class B: public A
{
public:
    virtual string f() const { return "B"; }
};

int main()
{
    //A a; // ошибка компиляции (error: cannot declare variable 'a' to be of abstract type 'A')
    B b;
    std::cout << b.f() << std::endl;

    return 0;
}