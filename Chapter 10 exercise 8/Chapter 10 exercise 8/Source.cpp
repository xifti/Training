#include <iostream>
#include <fstream>


//объединение двух текстовых файлов в один (сначала первый, потом второй)


void checkin_the_file_extension(std::string& s)
{
	const std::string TXT = ".txt";

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
}


int main()
{
	std::cout << "This program merges two text files into one."<<std::endl;
	std::cout << "Enter name first file: ";
	std::string first;
	std::cin >> first;

	checkin_the_file_extension(first);

	std::ifstream first_file{ first };
	if (!first_file)
	{
		std::cout << "Incorrect first file name" << std::endl;
		std::exit(-1);
	}

	std::cout << "Enter name second file: ";
	std::string second;
	std::cin >> second;

	checkin_the_file_extension(second);

	std::ifstream second_file{ second };
	if (!second_file)
	{
		std::cout << "Incorrect second file name" << std::endl;
		std::exit(-1);
	}

	std::cout << "Enter file name for saving: ";
	std::string result;
	std::cin >> result;

	checkin_the_file_extension(result);

	std::ofstream ofs{ result };

	ofs << first_file.rdbuf() << std::endl << second_file.rdbuf();

	return 0;
}