#include <iostream>
using namespace std;

template <class T> class CPair {
    T elements [2];
  public:
    CPair (T one, T two)
    {
	elements[0]=one;
	elements[1]=two;
    }
    T sum(){return elements[0]+elements[1];}
};

template <class T> class CPair<T*> {
    T* elements [2];
  public:
    CPair (T* one, T* two)
    {
	elements[0]=one;
	elements[1]=two;
    }
    T sum(){return *elements[0]+*elements[1];}
};
 
int main()
{
    int *a, *b;
    *a=1;
    *b=2;
    cout<< CPair<double>(10.0,20.0).sum()<<endl; // 30
    cout<< CPair<int *>(a,b).sum()<<endl; // 3 - вызывается частичная специализация для указателей. Можно проверить, что именно она, заменив выше на *elements[0]-*elements[1] (даст -1)
    return 0;
}