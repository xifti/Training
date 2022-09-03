#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;







vector<string> sort_name(vector<string> name);
void sort_age(vector<string>& name, vector<string>& name_sort, vector<double>& age);

void print_age_name(vector<string> name, vector<double> age)
{
	for (int i = 0; i < name.size(); ++i)
	{
		cout << '\n' << name[i] << '\t' << age[i] << endl;
	}
}

int main()
{
	vector<string> name;
	vector<double> age;
	cout << "Enter nemes" << endl;
	cout << "To stop the name set, type 'done'." << endl;
	string stop = "done";
	string names;
	double ages = 0.0;

	while (true)
	{
		cin >> names;
		if (names != stop)
		{
			name.push_back(names);
			cout << "Done" << endl;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < name.size(); ++i)
	{
		cout << "How old is the man with the name: " << name[i] << endl;
		cin >> ages;
		age.push_back(ages);
		cout << "Done" << endl;
	}

	vector<string>name_sort = sort_name(name);

	sort_age(name, name_sort, age);

}


vector<string> sort_name(vector<string> name)
{
	std::sort(name.begin(), name.end());

	return name;
}

void sort_age(vector<string>& name, vector<string>& name_sort, vector<double>& age)
{
	double term = 0.0;
	string LUL = "";
	for (int i = 0; i < name.size(); ++i)
	{
		if (name[i] != name_sort[i])
		{
			for (int r = 0; r < name_sort.size(); ++r)
			{
				if (name[i] == name_sort[r])
				{
					LUL = name[i];
					name[i] = name[r];
					name[r] = LUL;
					term = age[i];
					age[i] = age[r];
					age[r] = term;
				}


			}
		}
	}
	print_age_name(name_sort, age);
}