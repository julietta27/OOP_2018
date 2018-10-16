#include <iostream>
using namespace std;

template <class T> class CPair {
protected:
    T elements [2];
public:
    CPair (T one, T two)
    {
    	elements[0]=one;
	    elements[1]=two;
    }
    T sum(){return elements[0]+elements[1];}
};

template <class T> class AnotherPair: public CPair<T> {}; // класс-наследник

template <> class AnotherPair<int> : public CPair<int> {
public:
    AnotherPair (int* one, int* two):CPair(*one, *two){}
}; // специализация наследника для int
 
int main()
{
    int *a, *b;
    *a=1;
    *b=2;
    cout<< CPair<double>(10.0,20.0).sum()<<endl; // 30
    cout<< AnotherPair<int>(a,b).sum()<<endl; // 3 - вызывается частичная специализация для int
    return 0;
}