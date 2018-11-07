#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

bool my_func(std::vector<int> vec)
{ return std::equal(vec.cbegin(), vec.cbegin() + vec.size() / 2, vec.crbegin());}
    
int main()
{
    std::vector<std::vector<int>> v2 { {1,3,2}, {4,4,4}, {2,2,2}, {5,5,9} };
    std::vector<std::vector<int>>::iterator result1 = std::find_if(v2.begin(), v2.end(), std::bind(my_func,std::placeholders::_1));
    for (auto it = (*result1).begin(); it != (*result1).end(); it++) {
    std::cout << *it << " ";}
    result1 = std::find_if(result1+1, v2.end(), std::bind(my_func,std::placeholders::_1));
    for (auto it = (*result1).begin(); it != (*result1).end(); it++) {
    std::cout << *it << " ";}
    std::cout << "\n";
}
//4 4 4 2 2 2