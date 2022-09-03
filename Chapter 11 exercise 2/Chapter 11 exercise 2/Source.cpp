#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Эта программа ищет ключевое слово в выбранном вами фаиле, выводит всю строку содержащую это слово и номер этой строки в фаиле.


std::ifstream checkin_the_file_extension(std::string& s)
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
		std::cout << "Incorrect first file name" << std::endl;
		std::exit(-1);
	}
	return ist;
}


bool search_in_line(std::string& s,std::string& search)
{
	std::vector<std::string> words;
	std::string word;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word += s[i];
			if (i == s.size() - 1) { words.push_back(word); }
		}
	}

	for (int i = 0; i < words.size(); ++i)
	{
		std::string::size_type it;
		it = words[i].find(search);
		if (it != std::string::npos)
		{
			return true;
		}
	}


	return false;
}


int main()
{
	std::cout << "This program looks for a keyword in the selected file, outputs the whole line containing the word and the number of this line in the file." << std::endl;
	std::cout << "Enter file name: ";
	std::string search;

#if 0	//ver 1 работает, но если ввести 1 символ, то оно найдет все строки в которых есть слова с этим символом
	std::cin >> search;
	std::ifstream ist=checkin_the_file_extension(search);

	std::cout << "Enter a search word: ";
	std::cin >> search;

	int count=0;
	for (std::string line; std::getline(ist, line, '\n');)
	{
		++count;
		std::string::size_type it;
		it = line.find(search);
		if (it != std::string::npos)
		{
			std::cout << "Lines #" << count << " : " << line << std::endl;
		}
	}
#endif

#if 1 //ver 2 работает корректно (находит слова, а не символы в словах)
	std::cin >> search;
	std::ifstream ist = checkin_the_file_extension(search);

	std::cout << "Enter a search word: ";
	std::cin >> search;

	int count = 0;
	for (std::string line; std::getline(ist, line, '\n');)
	{
		++count;
		bool flag = search_in_line(line,search);

		if (flag == true)
		{
			std::cout << "Lines #" << count << " : " << line << std::endl;
		}

	}
#endif


	return 0;
}