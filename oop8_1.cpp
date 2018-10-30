#include <set>  
#include <string>  
#include <iostream>  
#include <functional>  
using namespace std;  
  
class BigObject  
{  public:  
    string id;  
    explicit BigObject(const string& s) : id(s) {}  
    bool operator< (const BigObject& other) const  
    {  return this->id < other.id;  }  
};  
  
inline bool operator<(const string& otherId, const BigObject& obj)  
{ return otherId < obj.id; }  
  
inline bool operator<(const BigObject& obj, const string& otherId)  
{  return obj.id < otherId; }  

int main()  
{  // s-суффикс определяет строковый литерал. C++14 
    BigObject b1{ "42F"s };   
    BigObject b2{ "52F"s };  
    BigObject b3{ "62F"s };  
    set<BigObject, less<>> myNewSet; // C++14. Второй параметр позволяет использовать не operator < класса BigObject, а любые определенные operator < для сравниваемых типов
    myNewSet.insert(b1);  
    myNewSet.insert(b2);  
    myNewSet.insert(b3);  
    auto it = myNewSet.find(string("62F"));  
    if (it != myNewSet.end())  
        cout << "element = " << it->id << endl;   
    else  
        cout << "element not found " << endl;  
return 0;  
}  
//Output: myNewSet element = 62F 