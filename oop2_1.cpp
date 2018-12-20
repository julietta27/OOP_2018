#include <iostream>

using namespace std;

int supercalculation(const bool choice)
{
	return 1 - (choice) ? -1 : 2;
}

int main()
{
	int KS30;
	bool choice;
	cout<<"Enter choice"<<endl;
	cin>>choice;
	cout<<"Super number "<<supercalculation<<endl;
	return 0;
}