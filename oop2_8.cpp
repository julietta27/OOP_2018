#include <iostream>
int main()
{
const int rowCount = 6;
const int colCount = 4;
int** a = new int*[rowCount];
for(int i = 0; i < rowCount; ++i)
  a[i] = new int[colCount];

for(int i = 0; i < rowCount; ++i)
  for(int j = 0; j < colCount; ++j)
    a[i][j] = i + j;
std::cout<<a[2][3]; // 5

for(int i = 0; i < rowCount; ++i) {
    delete [] a[i];
}
delete [] a;
    return 0;
}