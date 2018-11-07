#include <iostream>
#include <vector>
#include <numeric>
#include <string>
 
std::string func(std::string res, int x)
{
    return res += (x > 5) ? "0" : "1";
}
 
int main()
{
    std::vector<int> v{1, 3, 5, 7, 9, 11, 13, 0, 0, 2};
    std::string one = std::accumulate(v.begin(), v.end(), std::string(), func);
     std::cout << one << '\n';
} // 1110000111