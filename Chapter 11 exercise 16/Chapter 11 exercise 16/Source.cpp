#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>



// Программа считывает значения int разделенные пробелами,
// после чего сортирует, и выводит на экран(или сохраняет в фаил)
// сначала число, потом количество его повторений (если таковые имеются)
// то есть, если число встретилось 1 раз, то в строке будет только это число, без кол-ва повторений
// пример: строка "1 6 1 1 5 6 7"
// вывод:
// 1 3
// 5
// 6 2
// 7


#include <map>
#if 0  // ver 2 работает с потоком cin cout
int main() {
	std::map<int, std::size_t> counters;

	int n;
	while (std::cin >> n)
		++counters[n];

	for (auto [n, count] : counters) {
		std::cout << n;
		if (count > 1)
			std::cout << ' ' << count;
		std::cout << std::endl;
	}

	return 0;
}
#endif

#if 1 // ver 1 работает с потоком ifstream ofstream
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

	std::cout << "Enter file name for seving: ";
	std::cin >> file;
	std::ofstream ofs{ file };
	if (!ofs)
	{
		std::cout << "ERROR";
		exit(-1);
	}


	std::vector<int> v;

	for (int i = 0; ifs >> i; )
	{
		v.push_back(i);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		int count = 1;
		ofs << v[i];
		for (int j = i+1; j < v.size(); ++j)
		{
			if (v[i] != v[j])
			{
				i = j;
				break;
			}
			++count;
		}

		if (count > 1)
		{
			ofs <<' '<<count<<std::endl;
		}
		else
		{
			ofs << std::endl;
		}
	}

	return 0;
}
#endif