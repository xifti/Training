#include <iostream>
#include <fstream>





// Программа подсчитывает количество символов по разновидностям из фаила и сохраняет эту информацию в другой фаил (числа, маленькие буквы, большие буквы и тд)




int main()
{
	std::cout << "Enter file name: ";
	std::string file;
	std::cin >> file;
	std::ifstream ifs{ file };
	if (!ifs)
	{
		std::cout << "ERROR";
		exit(-1);
	}

	std::cout << "Enter file name to save: ";
	std::string file2;
	std::cin >> file2;
	std::ofstream ofs{ file2 };
	if (!ofs)
	{
		std::cout << "ERROR";
		exit(-1);
	}


	int digit=0;
	int lower=0;
	int upper=0;
	int punct=0;
	int space=0;
	int cntrl=0;
	
	char ch = 0;
	while(!(ifs.bad()||ifs.eof()) && ifs.get(ch))
	{
		if (isdigit(ch))
		{
			++digit;
		}
		else if (islower(ch))
		{
			++lower;
		}
		else if (isupper(ch))
		{
			++upper;
		}
		else if (ispunct(ch))
		{
			++punct;
		}
		else if (isspace(ch))
		{
			++space;
		}
		else
		{
			++cntrl;
		}
	}


	ofs << "The file consists of:"<< std::endl
		<< "Digit: " << digit << std::endl
		<< "Lower: " << lower << std::endl
		<< "Upper: " << upper << std::endl
		<< "Punct: " << punct << std::endl
		<< "Space: " << space << std::endl
		<< "Cntrl: " << cntrl << std::endl;




	return 0;
}