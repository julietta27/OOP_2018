#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

template <class T, class U> struct Comparator {
    static bool compare(const T& one, const U& two)
    { return two==one;} //one имеет тип int. Должен вызываться Dog::operator == (const int& another)
};
    
int main()
{
    struct Dog    {
        int weight;
        Dog(int d){weight=d;}
        bool operator == (const Dog& another) const {return this->weight==another.weight;} // выполняется неявное преобразование так как конструктор доупскает это
        //bool operator == (const int& another) const {return this->weight==another;}
    };

    std::vector<int> v{2,5,5,8,10,12};
    std::vector<Dog> d{2,5,5,8,10,12};
    std::cout << "Число пятерок: ";
    std::cout << std::count(v.cbegin(), v.cend(), 5) << "\n";
    std::cout << (std::equal(v.cbegin(), v.cend(), d.cbegin(), &Comparator<int,Dog>::compare)?"векторы v и d равны":"векторы v и d не равны")<< "\n";
}
//Число пятерок: 2
//векторы v и d равны