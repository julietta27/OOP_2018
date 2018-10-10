#include <iostream>
#include <string>
using namespace std;

template <class T, class U> T doCast(const U& u)
{
    return (T)u;
} 

template<> int doCast<int,double>(const double& u){return 0;}

//template<> string doCast<string, class U>(const U& u){return std::to_string(u);} // частичная (неполная) специализация шаблонов не разрешена!
template<> string doCast<string, int>(const int& u){return std::to_string(u);}

int main()
{
    std::cout << doCast<int,double>(5.33) << std::endl; // печатает 0
    std::cout << doCast<string,int>(74) << std::endl; // 74

}