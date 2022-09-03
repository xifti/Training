#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <iomanip>


// Программа считывает из файла числа разделенные пробельными символами
// После чего выводит в новый фаил эти числа в научном формате с точностью = 8, в 4 столбца размером по 20 символов в столбце



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
	std::cin >> file;
	std::ofstream ofs{ file };
	if (!ofs)
	{
		std::cout << "ERROR";
		exit(-1);
	}


	std::vector<double> v;

	for(double d=0;ifs>>d;)
	{
		v.push_back(d);
	}


	int j = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (j > 3)
		{
			ofs << std::endl;
			j = 0;
		}
		ofs << std::setw(20) << std::scientific << std::setprecision(8) << v[i];
		++j;
	}


	return 0;
}