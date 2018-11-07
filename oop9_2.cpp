#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
 
int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    } 
    std::for_each(vec.begin(), vec.end(), [] (int &i){i*=i;}); //0 1 4 9 16 25 36 49 64 81 
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(std::cout, " "));
}