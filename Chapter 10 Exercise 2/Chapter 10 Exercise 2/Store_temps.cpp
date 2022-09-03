#include <iostream>
#include <fstream>
#include <vector>
#include <string>



[[noreturn]] void error(const std::string& file_name)
{
	std::cout << "File with this name " << file_name << " was not found";
	std::exit(-1);
}

struct Reading
{
	int hour;
	double temperature;
};



int main()
{

	const std::string TXT = ".txt";
	std::string in_file_name;
	std::cout << "Enter name your .txt file (dont use '.txt'):" << std::endl;
	std::getline(std::cin, in_file_name);

	std::string::size_type it;
	it = in_file_name.find(TXT);
	if (it == std::string::npos)
	{
		in_file_name += TXT;
	}

	std::ifstream ist{ in_file_name };
	if (!ist)
	{
		error(in_file_name);
	}

	std::string out_file_name="raw_temps.txt";
	std::ofstream ost { out_file_name };
	if (!ost)
	{
		error(out_file_name);
	}

	std::vector<Reading> temps;
	int hour;
	double temperature;
	while (ist >> hour >> temperature)
	{
		if (hour < 0 || 23 < hour)
		{
			std::cout << "ERROR. Uncorrect time.";
			std::exit(-2);
		}
		temps.push_back(Reading{ hour,temperature });
	}

	for (int i = 0; i < temps.size(); ++i)
	{
		ost << '(' << temps[i].hour << ',' << temps[i].temperature << ')' << std::endl;
	}


	return 0;
}

