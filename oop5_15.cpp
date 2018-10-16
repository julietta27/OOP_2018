#include <iostream>
using namespace std;

template <typename T> class A
{
protected:
    T field;
public:
    A(T t):field(t){}
	virtual void fun()=0;
};

template <typename T> class B : public A<T>
{
public:
    B(T t):A<T>(t){}
	virtual void fun(){cout<<A<T>::field<<endl;}
};

int main()
{
    B<int> b(0xA8);
    b.fun();
    A<int>* c = new B<int>(22);
    c->fun(); // B::fun() - позднее связывание
    return 0;
}