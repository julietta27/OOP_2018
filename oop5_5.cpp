#include <iostream>
#include <string>
using namespace std;

class A
{
    int health = 10;
    int power = 20;
public:
    int getHealth(){return health;}
    int getPower(){return power;}
    int callMe(int (A::*method)())
    {
	    return (this->*method)();
    }
};

int main()
{
    A a;
// Через анонимный указатель на функцию (rvalue)
    std::cout << a.callMe(&A::getPower) << std::endl;
    
//объявим указатель на функцию (lvalue)
    int (A::*someMethod)();
    someMethod=&A::getHealth;
    std::cout << (a.*someMethod)() << std::endl;
    return 0;
}