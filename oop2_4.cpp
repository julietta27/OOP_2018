#include <iostream>
int main()
{
    int stack[2094000];
    stack[100-1]=8;
    std::cout<<sizeof(stack)/1024.0/1024.0;
    return 0;
}
