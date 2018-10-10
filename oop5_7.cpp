#include <iostream>
#include <string>
using namespace std;

template <class T, class U> T doCast(const U& u)
{
    return (T)u;
} 

int main()
{
    std::cout << doCast<int,double>(5.33) << std::endl; // печатает 5
    std::cout << doCast<int>(5.33) <<std::endl; // тоже. Самый правый параметр шаблон можно опустить, если он может быть неявно выведен (template argument deduction)
    std::cout << doCast<char,int>(74) << std::endl; // J
    std::cout << doCast<string,int>(74) << std::endl; /*main.cpp: In instantiation of 'T doCast(const U&) [with T = std::__cxx11::basic_string<char>; U = int]':
                                                        main.cpp:15:39:   required from here
                                                        main.cpp:7:12: error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(const int&)'
                                                        return (T)u; */
}