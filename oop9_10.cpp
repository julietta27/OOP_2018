#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
 
int main()
{
    std::vector<int> v{0, 5, 7, 7, -9, 11, -13};
    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 7);
    std::cout << *(it) << " " << *(it+1) << '\n'; //7 7
	it = std::max_element(v.begin(), v.end());
	std::cout << *(it) << '\n'; // 11
	it = std::max_element(v.begin(), v.end(), [](int a,int b){return std::abs(a)<std::abs(b);});
	std::cout << *(it) << '\n'; // -13
	std::string s = "laba";
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << '\n';
    } while (std::next_permutation(s.begin(), s.end())); //все возможные перестановки букв без повторений в порядке возрастания
}