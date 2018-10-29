#include <iostream>
#include <deque>        // нужен для использования контейнера
#include <iterator>     // нужен для использования итераторов
using namespace std;
int main()
{
    int dequeSize = 5;
    deque<char> dq1(dequeSize);     // создаем двустороннюю очередь
    for(int i = 0; i < dq1.size(); i++) { cin >> dq1[i];  }
// элегантный метод вывода на экран: копирование очереди в поток вывода с помощью стандартного алгоритма
    copy( dq1.begin(), dq1.end(), ostream_iterator<char>(cout," ") );
    double array[]={2.4, 43.3};
    deque<double> dq2(array,array+2);
    dq2.push_front(7.9);
    dq2.pop_back();
    for (auto & i: dq2)
         cout<<i<<endl; //7.9 2.4
    return 0;
}