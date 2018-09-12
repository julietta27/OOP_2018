#include <iostream>
#include <vector>
using namespace std;
int main()
{
const int rowCount = 6;
const int colCount = 4;
vector<vector<int> > a;
vector <int> b;

for(int i = 0; i < rowCount; ++i)
{
    b.clear();
    for(int j = 0; j < colCount; ++j)
      b.push_back(i + j);      
    a.push_back(b);
}
std::cout<<a[2][3]; // 5

    return 0;
}