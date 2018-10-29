#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector <int> v(2,10); // создаем вектор из 2 элементов, каждый элемент имеет значение 10
    vector <int>::iterator it;
    it = v.begin() + 1;// вектор указывает на v[1]
    v.insert(it,4); // v[0] = 10 v[1] = 4 v[2] = 10
    cout<<v[1]<<endl; // *it - недействительный
    it +=3; // v[4] не существует = недействительный итератор
    cout<<*it<<endl; // выдаст мусор
    if (it == v.end()) // v[3] не существует и it+=2 было бы == v.end()
        cout<<“invalid iterator due to container end”<<endl; // не выводится
    return 0;
}