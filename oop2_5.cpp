#include <iostream>
 
int main()
{
    int array[] = { 3, 8, 4 };
 
    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 0 is at address: " << array+0 << '\n';
    std::cout << "Element 1 is at address: " << array+1 << '\n';
    std::cout << "Element 0 is at address: " << *array+0 << '\n';
    std::cout << "Element 1 is at address: " << *array+1 << '\n';
 
    return 0;
}