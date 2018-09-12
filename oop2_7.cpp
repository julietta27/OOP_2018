#include <iostream>
int main()
{
int a[100], b[100];
int *pa = a;  // или int *p = &a[0];
std::cout<< sizeof(a)/sizeof(int)<<std::endl; //100
std::cout<<sizeof(pa)/sizeof(int)<<std::endl; //размер указателя pa всегда одинаков! Не удается узнать размер массива данным образом
    return 0;
}
