#include <iostream>
typedef int MyType;
int main()
{
    std::cout<<sizeof(MyType)<<std::endl;
	char x[sizeof(MyType)]={0x0011u,0,0,0}; //11 hex = 17
	//char x[sizeof(MyType)]={0x0011u,0,0,0,0};// ошибка компиляции, можно подать только 4 значения
	MyType* pointer = new( &x[0] ) MyType;
	std::cout<<*pointer<<std::endl;
	int* pointer2=pointer;
	std::cout<<*pointer2<<std::endl;
    return 0;
}