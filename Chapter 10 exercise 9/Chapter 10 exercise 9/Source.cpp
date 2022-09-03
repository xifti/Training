#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

//Программа берет 2 отсортированных(лексикографически) фаила объеденяет их и сортирует(лексикографически) снова


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


void file_in_vector(std::ifstream& is, std::vector<std::string>& v)
{
	std::string s;
	while (is >> s)
	{
		v.push_back(s);
	}
}


int main()
{
	std::vector<std::string> v_for_sorting;
	std::cout << "This program takes two sorted files with words separated by spaces ' ' characters and combines them into one file, sorting again." << std::endl;
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
	file_in_vector(first_file, v_for_sorting);

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
	file_in_vector(second_file, v_for_sorting);

	
	std::sort(v_for_sorting.begin(), v_for_sorting.end());


	std::cout << "Enter file name for saving: ";
	std::string result;
	std::cin >> result;
	checkin_the_file_extension(result);
	std::ofstream ofs{ result };


	for (int i = 0; i < v_for_sorting.size(); ++i)
	{
		ofs << v_for_sorting[i] << ' ';
	}



	return 0;
}