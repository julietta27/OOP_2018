#include <iostream>
using namespace std;

template <class T=int> class CPair {
    T elements [2];
  public:
    CPair (T one, T two)
    {
	elements[0]=one;
	elements[1]=two;
    }
    T sum(){return elements[0]+elements[1];}
};
 
int main()
{
    cout<<CPair<>(10.0,20.0).sum()<<endl;
    return 0;
}