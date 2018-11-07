#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <cstdlib>
 
int main()
{
    std::vector<int> vec;
    vec.resize(10);
    srand(time(NULL));
    // нельзя: fill принимает только значение последним параметром…
    //std::fill(vec.begin(), vec.end(), [] (void){return rand()%10;});
    std::generate(vec.begin(), vec.end(), [] (void){return rand()%10;}); 
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(std::cout, " "));
}

//возможный вывод: 9 9 3 9 5 1 7 8 7 7 