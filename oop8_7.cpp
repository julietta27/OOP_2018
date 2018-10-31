#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string>
using namespace std;
 
struct data {                                  // запись о студенте 
 string fio;
 int group, age, scholarship;
 inline friend ostream& operator <<(ostream& out, const struct data& obj) {
 return cout << "[ " << obj.fio << " : " << obj.group << " : "
 << obj.age << " : " << obj.scholarship << " ]";
 }
};
 
struct comp_data {                             // функтор сравнения 
 int what;
 bool compare(const struct data& f, const struct data& s) {
 switch (abs(what)) {
 case 1: return f.fio < s.fio;
 case 2: return f.group < s.group;
 case 3: return f.age < s.age;
 case 4: return f.scholarship < s.scholarship;
 default: return false;
 }
 }
public:
 comp_data(int what) : what(what) {}
 bool operator()(const struct data& f, const struct data& s) {
 bool ret = compare(f, s);
 return what >= 0 ? ret : !ret;
 }
};
 
class faculty : public vector<struct data> {   // журнал 
public:
 faculty(const vector<struct data>& ini) {
 for (auto &x : ini) this->push_back(x);
 }
 inline friend ostream& operator <<(ostream& out, const faculty& obj) {
 for (auto &x : obj) out << x << endl;
 return out;
 }
};
 
int main(void) {
 faculty filology = (vector< struct data >({
 { "Petrov", 12, 19, 1500 },
 { "Ivanov",  13, 20, 0 },
 { "Alexeev",  11, 21, 0 },
 { "Nikolaev",  10, 45, 2000 },
 }));
 cout << filology;
 int mode=1;
 sort(filology.begin(), filology.end(), comp_data(mode));
 cout << filology;
}