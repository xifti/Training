#include <iostream>
#include <vector>


using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;




void print_until_s(const vector<string>&v, const string& quit)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit) { return; }
		cout << v[i] << endl;
	}
}

void print_until_ss(vector<string>v, string quit)
{
	int count=0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit) { ++count; }
		if (count==2) { return; }
		cout << v[i] << endl;

	}
}



int main()
{
	print_until_ss({ "Pupa","Lupa", "Bugalteriya", "Vse_pereputali", "Zarplata", "Prishli", "Radost'", "Agressiya", "Radost'" }, "Radost'");
	return 0;
}