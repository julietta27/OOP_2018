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
    std::remove_if(vec.begin(), vec.end(), std::bind(std::less<int>(),std::placeholders::_1,4)); //4 5 6 7 8 9 6 7 8 9 
    // корректно - с изменением размера контейнера:
    //std::vector<int>::iterator it=std::remove_if(vec.begin(), vec.end(), std::bind(std::less<int>(),std::placeholders::_1,4)); //4 5 6 7 8 9
    //vec.erase(it,vec.end());    
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(std::cout, " "));
}