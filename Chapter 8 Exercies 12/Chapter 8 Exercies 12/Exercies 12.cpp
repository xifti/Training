#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;

vector<int> booba(const vector<string>&v)
{

	vector<int> OMEGALUL;
	vector<string>::const_iterator it;
	for (it = v.begin(); it != v.end();++it)
	{
		OMEGALUL.push_back(it->size());
	}

	return OMEGALUL;
}



void mes(vector<string>&v)
{
	int x = v.size();
	sort(v.begin(), v.end());
	cout <<"Lexographically, the first line: '" << v[0]<<"'" << '\n' 
		<<"Lexographically, the last line: '" << v[x - 1]<<"'" << endl;
}

void print_int(const vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return;
}

void print_minmax(const vector<string>& v, const vector<int>& n)
{
	int max = 0;
	int min = 2147483647;
	int min_i = 0;
	int max_i = 0;

	for (int i = 0; i < n.size(); ++i)
	{
		if (max < n[i])
		{
			max = n[i];
			max_i = i;
		}
		if (min > n[i])
		{
			min = n[i];
			min_i = i;
		}
	}

	cout << "The shortest word: '" << v[min_i] << "' consists of '" << n[min_i] << "' characters." << endl;
	cout << "The longest word: '" << v[max_i] << "' consists of '" << n[max_i] << "' characters." << endl;
	return;

}

int main()
{
	vector<string> v = { "Bipki", "Lupa", "Pupa", "Zarplata", "Bugalteriya", "Pereputali" };
	
	vector<int> OMEGALUL = booba(v);

	print_int(OMEGALUL);

	print_minmax(v, OMEGALUL);
	
	mes(v);
}
