#include <iostream>
#include <vector>
#include <algorithm>







class Name_pairs
{
public:
    void read_names(Name_pairs& t);
	void read_ages(Name_pairs& t);


	void v_sort(std::vector <std::string> n, std::vector<double>& a, Name_pairs& t);

	std::string names;
	double ages;
	std::vector <std::string> name;
	std::vector<double> age;

	bool operator==(const Name_pairs& t);
	bool operator!=(const Name_pairs& t);
};


bool Name_pairs::operator== (const Name_pairs& t)
{
	if (name.size() <= 1||age.size() <= 1) 
	{ 
		std::cout << "You did not enter a name/age value\n";
		return 0; 
	}

	int size = name.size()-1;
	return (name[0] == name[size] && age[0] == age[size]);
}

bool Name_pairs::operator!= (const Name_pairs& t)
{
	if (name.size() <= 1 || age.size() <= 1)
	{
		std::cout << "You did not enter a name/age value\n";
		return 0;
	}

	int size = name.size() - 1;
	return (name[0] != name[size] && age[0] != age[size]);
}


void Name_pairs::read_names(Name_pairs& t)
{
	std::string s;
	while (1)
	{
		
		std::cin >> s;

		if (s == "exit")
		{
			break;
		}
		t.names = "";
		
		t.names = s;
		t.name.push_back(t.names);
		t.read_ages(t);

	}
	

	t.v_sort(t.name,t.age,t);

	if (t == t)
	{
		std::cout << "The first and last recorded name and age are equal\n";
	}
	if (t != t)
	{
		std::cout << "First and last recorded name and age are not equal\n";
	}

}


void Name_pairs::read_ages(Name_pairs& t)
{
	std::cout<< "y.o. " << t.names << '\n';
	std::cin >> t.ages;
	t.age.push_back(t.ages);
	return;


}

void Name_pairs::v_sort(std::vector <std::string> n, std::vector<double>& a, Name_pairs& t)
{
	sort(n.begin(), n.end());

	for (int i = 0; i < n.size(); ++i)
	{
		for (int j = i+1; j < t.name.size(); ++j)
		{
			if (n[i] == t.name[j])
				std::swap(t.age[i], t.age[j]);
		}
	}
	t.name = n;

}

std::ostream& operator<<(std::ostream& os, Name_pairs& t)
{
	for (int i = 0; i < t.name.size(); ++i)
	{
		 os <<'(' << t.name[i] << ',' << t.age[i] << ')' << '\n';
	}
	return os;
}

int main()
{


	Name_pairs t;

	t.read_names(t);

	std::cout << t;

	return 0;
}