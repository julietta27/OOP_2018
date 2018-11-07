#include <iostream>  
#include <functional>  
  int main() {  
    using namespace std;  
// данная лямбда возвращает другую лямбду типа function<int(int)>, которая сложит с x уже свое число y. Так, addtwointegers(7) вернет лямбду, которая складывает 7 и произвольное число.
    // another lambda expression that adds two numbers.   
    // The returned lambda expression captures parameter x by value.  
    auto addtwointegers = [](int x) -> function<int(int)> {   
        return [=](int y) { return x + y; };   
    };  
    // Лямбда принимает лямбду как аргумент (лямбда-выражение высшего порядка).
    // Передает аргумент z в функцию f и умножает результат на 2.
    auto higherorder = [](const function<int(int)>& f, int z) {   
        return f(z) * 2;   
    };  
    // вызов функции высшего порядка
    auto answer = higherorder(addtwointegers(7), 8);  
    // 7 будет сложено с числом 8: f(z), z = 8. А затем, умножено на 2. Итог: (7+8)*2
    cout << answer << endl; //30 
}
// https://msdn.microsoft.com/ru-ru/library/dd293599.aspx