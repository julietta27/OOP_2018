#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
int main(){
  std::map<int,int> map1;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  for (int i=0; i<10000000; i++)
    map1.insert(std::make_pair(i, i+1)); 
  std::map<int,int>::iterator i1;
  if ((i1=map1.find(180989)) == map1.end()) 
    std::cout << "Vasya not found\n";
  else
    std::cout << "Vasya: "<<(*i1).second<<"\n";
  std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  
  std::map<int,int> map2;
  std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
  for (int i=0; i<10000000; i++)
    map2.insert(std::make_pair(i, i+1)); 
  std::map<int,int>::iterator i2;
  if ((i2=map2.find(180989)) == map2.end()) 
    std::cout << "Vasya not found\n";
  else
    std::cout << "Vasya: "<<(*i2).second<<"\n";
  std::chrono::steady_clock::time_point end2= std::chrono::steady_clock::now();
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() <<std::endl;
}