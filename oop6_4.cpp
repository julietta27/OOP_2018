#include <iostream>
#include <list>     // список
#include <iterator>
#include <ctime>
#include <cstdlib>
using namespace std;
 
int main()
{
   list<int> l1;
   for(int i = 0; i < 15; i++)
       l1.push_back(rand()%5);
   l1.sort();   // сортировка
   cout << "\nСписок отсортирован по возрастанию: ";
   copy(l1.begin(), l1.end(), ostream_iterator<int>(cout," "));
   l1.unique();   // удаление дубликатов
   l1.reverse(); // перевернуть список
   l1.merge(std::move(list<int>{8,8,9}));
   cout << "\nПосле объединения: ";
   copy(l1.begin(), l1.end(), ostream_iterator<int>(cout," "));
   return 0;
}