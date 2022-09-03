#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <numeric>




//Программа суммирует последовательность чисел из фаила.



[[noreturn]]void error(const std::string & file_name)
{
	std::cout << "File with this name " << file_name << " was not found";
	std::exit(-1);
}



int main()
{

	std::string file_name;
	std::cout << "Enter name your .txt file (dont use '.txt'):" << std::endl;
	std::getline(std::cin, file_name);
	file_name += ".txt";
	

	std::ifstream ist{file_name};
	if (!ist)
	{
		error(file_name);
	}

	int64_t sum = 0;

#if 0 //ver 1  для идеальных условий, когда в файле все объекты являются числами разделенные пробелами (' ').
	std::cout << accumulate(std::istream_iterator<int>{ist}, std::istream_iterator<int>{}, sum) << std::endl;
#endif


#if 0  //ver 2 для файлов в которых встречаются не только числа но и строки, НО строку "123а" эта версия воспринимает как число "123", а "а123" как строку.
	while(!(ist.eof()||ist.bad()))
	{
		int64_t n;
		ist >> n;

		if (ist.fail())
		{
			ist.clear();
			ist.ignore(1); //игнорируем 1 символ.
		}
		else
		{
				sum += n;
		}
	}


	std::cout << sum;
#endif


#if 1  //ver 3 суммирует ТОЛЬКО числа разделенные пробельными символами ' ' ("123a" и "а123" для этой версии - строки).
	char ch = ' ';

	while (!(ist.eof() or ist.bad()))
	{
		char previous;
		previous = ch;

		ist.get(ch);

		if ((std::isdigit(ch) or ch == '-' or ch == '+') and (previous == ' ' or std::iscntrl(previous)))
		{
			std::string s;
			s += ch;

			while (ist.get(ch) && std::isdigit(ch))
			{
				s += ch;
			}

			if (std::isblank(ch) or std::iscntrl(ch) or ist.eof())
			{
				sum += stoi(s);
			}
		}

	}


	std::cout << sum;
#endif

	return 0;
}