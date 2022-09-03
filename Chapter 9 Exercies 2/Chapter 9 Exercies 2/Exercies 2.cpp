#include <iostream>
#include <vector>
#include <algorithm>
/*
НЕ РАБОТАЕТ вроде вносит значения в вектор, но почему-то не печает отсортированные результаты.

*/


const char NAME = 'N';
const char AGE = 'A';
const char prompt = '>';
const char print = ';';
const char quit = 'Q';
const std::string result = " = ";



struct Name_pairs
{
	char kind;
	std::string names;
	double ages;

	Name_pairs(char ch) :kind{ ch }, names{ "" }, ages{0.0} { }
	Name_pairs(char ch, std::string n) : kind{ ch },  names{ n }, ages{ 0.0 } { }
	Name_pairs(char ch, double a) : kind{ ch },  names { "" }, ages{ a } { }


	void print_v(std::vector<std::string>, std::vector<double>); //нужно сделать константной

	void read_names(Name_pairs& t);
	void read_ages(Name_pairs& t);

	std::vector<std::string> name; 
	std::vector<double> age;       
};

class Name_pairs_stream
{
private:
bool full;
Name_pairs buffer;
std::istream& strm;

public:

	Name_pairs_stream(std::istream& is = std::cin) :full{ 0 }, buffer{ 0 }, strm{ is } { }
	Name_pairs get();
	void unget(Name_pairs t) { buffer = t; full = true; }
	void ignore(char c);
};

Name_pairs Name_pairs_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;

	strm >> ch;
	switch (ch)
	{
	case print:
	case quit:
	return Name_pairs(ch);
	case'.':
	case'0':
	case'1':
	case'2':
	case'3':
	case'4':
	case'5':
	case'6':
	case'7':
	case'8':
	case'9':
	{
		strm.unget();
		double val;
		strm >> val;
		return Name_pairs(AGE, val);
	}
	default:
		if (isspace(ch))
		{
			return Name_pairs(print);
		}

		if (isalpha(ch))
		{
			std::string s;
			s += ch;
			while (strm.get(ch) && (isalpha(ch)))
			{
				s += ch;
			}
			strm.unget();

			return Name_pairs(NAME, s);
		}
		else
		{
			std::cout << "Bad token" << '\n';
		}
	}
}

void Name_pairs_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (strm >> ch)
	{
		if (ch == c) return;
	}
}

Name_pairs_stream ts;


void print_v(std::vector<std::string>& name, std::vector<double>& age)
{
	for (int i = 0; i < name.size(); ++i)
	{
		std::cout << name[i] << ' ' << age[i] << '\n';
	}
}


void Name_pairs::read_names(Name_pairs& t)
{
 while (true)
 {
	Name_pairs t = ts.get();

	if (t.kind == NAME)
	{
		t.name.push_back(t.names);
    }
	else if (t.kind==AGE)
	{
		t.age.push_back(t.ages);
	}
	else if (t.kind == print)
	{
		return;
	}
 }
}


void Name_pairs::read_ages(Name_pairs& t)
{
	t.age.push_back(t.ages);
	return;
}



int main()
{
	while (true)
	{
		std::cout << prompt;
		Name_pairs t = ts.get();
		while (t.kind == print)
		{
			t = ts.get();
		}

		if (t.kind == quit)
		{
			return 0;
		}

		ts.unget(t); //Ангетим T для того чтобы обратиться к первому элементу класса и последующим
		

		t.read_names(t);


		for (int i = 0; i < t.name.size(); ++i)
		{
			std::cout << t.name[i] << ' ' << t.age[i] << '\n';
		}
	}

	return 0;
}

