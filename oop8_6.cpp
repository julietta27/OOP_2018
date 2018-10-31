#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
//-------------------------------------------------------------------------------------------- 
// Быстрая сортировка. Сложность в среднем O( n*log(n) ), но в худшем случае O( n*n ) 
void sort1( vector<unsigned>& v ) { 
   sort( v.begin(), v.end() ); 
}
//-------------------------------------------------------------------------------------------- 
bool sort_function( unsigned f, unsigned s ) { return f > s; } 
 
void sort2( vector<unsigned>& v ) { // использование функции как предикакта 
   sort( v.begin(), v.end(), sort_function ); 
}
//-------------------------------------------------------------------------------------------- 
struct sort_class {   // функтор сравнения 
   bool operator()( unsigned f, unsigned s ) { return f > s; } 
};

void sort3( vector<unsigned>& v ) { 
   sort( v.begin(), v.end(), sort_class() ); 
}
//-------------------------------------------------------------------------------------------- 
// Сортировка подпоследовательности. Гарантированная сложность O( n*log(n) ) в любом случае. 
// Обычно сортировка в куче выполняется в 2-5 раз медленнее быстрой сортировки sort(). 
void sort4( vector<unsigned>& v ) { 
   partial_sort( v.begin(), v.end(), v.end() ); 
}
//-------------------------------------------------------------------------------------------- 
// Сортировка слиянием. Сложность O( n*log(n) ) или O( n*log(n)*log(n) ), если без дополнительной памяти 
void sort5( vector<unsigned>& v ) { 
   stable_sort( v.begin(), v.end() ); 
}
//-------------------------------------------------------------------------------------------- 
// Сортировка в куче (heap) - вызывают функции, непосредственно работающие с кучей 
// (то есть с бинарным деревом, используемым в реализации этих алгоритмов). 
// Сложность O( n+n*log(n) ) 
void sort6( vector<unsigned>& v ) { 
   make_heap( v.begin(), v.end() ); 
   sort_heap( v.begin(), v.end() ); 
}

int main()
{
    vector<unsigned> v(1000000);
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    sort1(v);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    std::cout << "Quick sort (STL) = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() <<std::endl;
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    sort2(v);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    std::cout << "Quick sort (STL) with predicate \">\" = " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() <<std::endl;
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
    sort3(v);
    std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
    std::cout << "Quick sort (STL) with functor = " << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3).count() <<std::endl;
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin4 = std::chrono::steady_clock::now();
    sort4(v);
    std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
    std::cout << "Partial sort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4).count() <<std::endl;
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin5 = std::chrono::steady_clock::now();
    sort5(v);
    std::chrono::steady_clock::time_point end5 = std::chrono::steady_clock::now();
    std::cout << "Stable sort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end5 - begin5).count() <<std::endl;
    std::generate(v.begin(), v.end(), std::rand);
    std::chrono::steady_clock::time_point begin6 = std::chrono::steady_clock::now();
    sort6(v);
    std::chrono::steady_clock::time_point end6 = std::chrono::steady_clock::now();
    std::cout << "Heap sort = " << std::chrono::duration_cast<std::chrono::milliseconds>(end6 - begin6).count() <<std::endl;

    return 0;
}