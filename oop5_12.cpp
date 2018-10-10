#include <iostream>
using namespace std;

double sum(const double& a, const double& b)
{
    return a+b;
}

template <class T, T (*someFunc)(const T&, const T&)> class CPair {
    T elements [2];
  public:
    CPair (T one, T two)
    {
	elements[0]=one;
	elements[1]=two;
    }
    T action(){return someFunc(elements[0],elements[1]);}
};

constexpr string (*s)(const string &, const string &)=NULL; //метод никогда не будет вызван
template <> string CPair <string, s> ::action(){return "Складывать строки я запретил!";}

int main()
{
	cout<< CPair<double, &sum >(10.0,20.0).action()<<endl; //30
    cout<< CPair<string, s>("что","тут").action()<<endl; //Складывать строки я запретил
    return 0;
}