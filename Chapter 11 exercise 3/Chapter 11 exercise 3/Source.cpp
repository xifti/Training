#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Программа открывает фаил, удаляет все главсные буквы из текста и получившийся результат записывает в новый фаил




std::ifstream checkin_the_file_extension_ifstream(std::string& s)
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

std::ofstream checkin_the_file_extension_ofstream(std::string& s)
{
	const std::string TXT = ".txt";

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
	std::ofstream ost{ s };

	return ost;
}



#if 0 //ver 1 почему-то в голову сразу пришла идея использовать vector, хотя он тут не нужен
std::string delete_vowels(std::string& s)
{
	int count=0;
	std::vector<int> counters;
	for (int i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
			case 'A':  case 'a':
			case 'E':  case 'e':
			case 'I':  case 'i':
			case 'O':  case 'o':
			case 'U':  case 'u':
			case 'Y':  case 'y':
			{
				counters.push_back(count);
				break;
			}
			default:
			{
				break;
			}
		}
		++count;
	}

	for (int i = counters.size()-1; i >= 0; --i)
	{
		s.erase(counters[i], 1);
	}

	return s;
}
#endif


#if 1 //ver 2
std::string delete_vowels(std::string& s)
{
	int count = 0;
	std::string new_line;
	for (int i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
		case 'A':  case 'a':
		case 'E':  case 'e':
		case 'I':  case 'i':
		case 'O':  case 'o':
		case 'U':  case 'u':
		case 'Y':  case 'y':
		{
			break;
		}
		default:
		{
			new_line += s[i];
			break;
		}
		}
		++count;
	}

	return new_line;
}
#endif


int main()
{
	std::cout << "The program opens a file, deletes all the main letters from the text, and writes the result to a new file." << std::endl;
	std::cout << "Enter the name of the source file: ";
	std::string search;
	std::cin >> search;
	std::ifstream ist = checkin_the_file_extension_ifstream(search);
	std::cout << "Enter a name for the saved file: ";
	std::cin >> search;
	std::ofstream ost= checkin_the_file_extension_ofstream(search);


	for (std::string line; std::getline(ist, line, '\n');)
	{
		std::string new_line = delete_vowels(line);
		new_line += '\n';
		ost << new_line;
	}


	return 0;
}