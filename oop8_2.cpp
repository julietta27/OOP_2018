#include <iostream>
#include <map>
#include <unordered_map>
int main(){
  std::map<std::string,int> map1 { {"Vasya",1908},{"Petya",1999} };
  map1["Masha"] = 2000;
  for(auto p : map1) std::cout << '{' << p.first << ',' << p.second << "} ";
  map1.erase("Masha");
  std::cout << " size: " << map1.size() << std::endl;

  std::unordered_map<std::string,int> map2 { {"Vasya",1908},{"Petya",1999} };
  map2["Masha"] = 2000;
  for(auto p : map2) std::cout << '{' << p.first << ',' << p.second << "} ";
  map2.erase("Masha");
  std::cout << " size: " << map1.size() << std::endl;
  map2.insert(std::make_pair("Mamasha", 1918)); 
  std::unordered_map<std::string,int>::iterator i;
  if ((i=map2.find("Vasya")) == map2.end()) 
    std::cout << "Vasya not found\n";
  else
    std::cout << "Vasya: "<<(*i).second<<"\n";  
}