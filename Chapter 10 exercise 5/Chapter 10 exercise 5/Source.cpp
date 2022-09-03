#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int not_a_reading = -7777; //ниже абсолютного нуля
const int not_a_month = -1; 

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;


struct Reading
{
	int day;
	int hour;
	double temperature;
};

struct Day 
{
	std::vector<double> hour{ std::vector<double>(24,not_a_reading) };
};


struct Month 
{
	int month{ not_a_month };
	std::vector<Day> day{ 32 };
};

void end_of_loop(std::istream& ist, char term, const std::string& message)
{
	if (ist.fail())
	{
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;
		std::cout << message << std::endl;
		std::exit(-1);
	}
}

std::istream& operator>>(std::istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
	{
		std::cout << "INVALID INPUT (d,h,t)" << std::endl;
		std::exit(-1);
	}

	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}


bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day) { return false; }
	if (r.hour < 0 || 23 < r.hour) { return false; }
	if (r.temperature < implausible_min || implausible_max < r.temperature) { return false; }

	return true;
}

std::istream& operator>>(std::istream& is, Month& m)
{
	char ch = 0;
	if (is >> ch && ch != '{')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::string month_marker;
	std::string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
	{
		std::cout << "INVALID INPUT (month)" << std::endl;
		std::exit(-1);
	}

	m.month = std::stoi(mm);

	Reading r;
	int duplicates = 0;
	int invalids = 0;

	for (Reading r; is >> r;)
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading)
			{
				++duplicates;
				m.day[r.day].hour[r.hour] = r.temperature;
			}
			else
			{
				++invalids;
			}
		}
	}

	if (invalids)
	{
		std::cout << invalids << " data in the 'month' class is corrupted" << std::endl;
	}

	if (duplicates)
	{
		std::cout << duplicates << " repeating data in 'month'" << std::endl;
	}

	end_of_loop(is, '}', "Wrong end of 'Month'");
	return is;
}


struct Year
{
	int year;
	std::vector<Month> month{ 12 };
};


std::istream& operator>>(std::istream& is, Year& y)
{
	char ch;
	is >> ch;

	if (ch != '{')
	{
		is.unget();
		is.clear(std::ios::failbit);
		return is;
	}

	std::string year_marker;
	int yy;
	is >> year_marker >> yy;

	if (!is || year_marker != "year")
	{
		std::cout << "INVALID INPUT (year)" << std::endl;
		std::exit(-1);
	}

	y.year = yy;

	while (true)
	{
		Month m;
		if (!(is >> m)) { break; }
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "Wrong end of 'Year'");
	return is;
}




void print_year(std::ofstream& ofs, const Year& y)
{
	ofs << "{ year: " << y.year <<" }" << std::endl;
}





int main()
{
	std::cout << "Enter name .txt fail: ";
	std::string iname;
	std::cin >> iname;

	std::ifstream ifs{ iname };

	if (!ifs)
	{
		std::cout << "Incorrect filename" << std::endl;
		std::exit(-1);
	}
	ifs.exceptions(ifs.exceptions() | std::ios_base::badbit);


	std::cout << "Enter name for saving fail .txt: ";
	std::string oname;
	std::cin >> oname;
	std::ofstream ofs{ oname };
	if(!ofs)
	{
		std::cout << "Incorrect filename for saving" << std::endl;
		std::exit(-1);
	}


	std::vector<Year> ys;

	while (true)
	{
		Year y;
		if (!(ifs >> y)) { break; }
		ys.push_back(y);
	}

	std::cout << "Counted " << ys.size() << " annual records" << std::endl;

	for (Year& y : ys)
	{
		print_year(ofs, y);
	}




	return 0;
}