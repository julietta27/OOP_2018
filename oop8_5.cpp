#include <iostream> 
#include <vector> 
using namespace std;
 
template <class T> class summator : public vector<T> {
public:
 summator(const vector<T>& v) {
   for (auto value : v)
     this->push_back(value);
 }
 
 T operator()(void) {
   T sum = 0;
   for (auto i: *this)
     sum+=i;
   return sum;
 }
};
 
int main(void) {
 summator <int> sums(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })); 
 cout << "sum = " << sums() << endl;
}