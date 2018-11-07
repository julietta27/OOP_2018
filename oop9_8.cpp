#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <cstdlib>
 
int main()
{
    std::vector<int> vec{1,2,4,5};
    int i=1,j=1;
    std::function <int(int&)> not_anon = [i,&j] (int& val) {return val+=i+j;}; // i captured by value, j captured by reference
    //std::transform(vec.begin(), vec.end(), vec.begin(), [i,&j] (int& val){return val+=i+j;});
    std::transform(vec.begin(), vec.end(), vec.begin(), not_anon);
    std::copy(vec.begin(), vec.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    i=888,j=100; //change of i does not affect the result below
    std::transform(vec.begin(), vec.end(), vec.begin(), not_anon);
    std::copy(vec.begin(), vec.end(),
        std::ostream_iterator<int>(std::cout, " "));
}
//3 4 6 7
//104 105 107 108