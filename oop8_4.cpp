#include <iostream>
#include <map>

int main(){
  std::multimap<int,int> map1;
  for (int i=0; i<3; i++)
    map1.insert(std::make_pair(0,i));
  for (auto n: map1)
    std::cout<<n.first<<" "<<n.second<<std::endl;
}