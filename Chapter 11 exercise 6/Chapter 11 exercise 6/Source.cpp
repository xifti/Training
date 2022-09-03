#include <iostream>
#include <fstream>
#include <string>
#include <vector>


//Программа удаляет все символы ('.' ';' ',' '?' '-' '\'') из текстового фаила


std::ifstream checkin_the_file_extension(std::string& s) //проверка написал ли юзер .txt в конце строки входящей в cin, если нет, то добавляем в конец строки
{
	const std::string TXT = ".txt";

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
	std::ifstream ist{ s };
	if (!ist)
	{
		std::cout << "Error file name.";
		exit(-1);
	}

	return ist;
}


std::string removing_delimiters(std::string& s)
{
	std::vector<int> counters;

	int counter = 0;
	for (int i =0; i<s.size();++i)
	{
		if (s[i] == '.' || s[i] == ';' || s[i] == ',' || s[i] == '?' || s[i] == '-' || s[i] == '\'')
		{
			counters.push_back(counter);
		}
		++counter;
	}


	for (int i = counters.size()-1; 0 <= i; --i) //начинаем удалять с конца, потому что при удалении s.size() меняется
	{
		s.erase(counters[i], 1);
	}


	return s;
}




int main()
{
	std::cout << "Enter file name: ";
	std::string search;
	std::cin >> search;
	std::ifstream ist = checkin_the_file_extension(search);

	for (std::string line; std::getline(ist, line, '\n');)
	{
		line= removing_delimiters(line);
		line += '\n';

		std::cout << line;
	}




	return 0;
}