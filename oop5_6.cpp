#include <iostream>
#include <string>
using namespace std;

class A
{
    public:
        A(int _h):health(_h){}
        int health;
};

int main()
{
    A a(7);
    int A::*some_field=&A::health;
    std::cout << a.*some_field << std::endl;
    return 0;
}