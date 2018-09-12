#include <iostream>
#include <string>
#include <vector>
//http://en.cppreference.com/w/cpp/language/union
union S
{
    std::string str;
    std::vector<int> vec;
    ~S() {} };
// объединение занимает max(sizeof(string), sizeof(vector<int>))
 
int main()
{
    S s = {"Hello, world"};
    
// чтение из s.vec есть undefined behavior в данном месте кода (неактивный член объединения)
    std::cout << "s.str = " << s.str << '\n';
    s.str.~basic_string<char>();
    new (&s.vec) std::vector<int>; //placement new
    // теперь s.vec – активный член объединения
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';
    s.vec.~vector<int>();
    return 0;
}