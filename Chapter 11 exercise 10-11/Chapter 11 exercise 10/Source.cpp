#include <iostream>
#include <vector>
#include <string>

// Программа возвращает вектор подстрок разделённых заданными пользователем символами (если пользователь не ввёл символ, то устанавливается символ по умолчанию (" ") )




std::vector<std::string> split (std::string& s, std::string& w)
{

	char ch;
	std::string ss;
	std::vector<std::string> v;

	if (w == " ")
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i]))
			{
				ss += s[i];


			}
			else if (s[i] = ' ')
			{
				v.push_back(ss);
				ss = "";
			}
		}
	}
	else
	{
		for (int i = 0; i < s.size(); ++i)
		{
			std::string::size_type it;
			it = w.find(s[i]);
			if (it == std::string::npos)
			{
				ss += s[i];
			}
			else if(it!= std::string::npos)
			{
				v.push_back(ss);
				ss = "";
			}
		}
	}
	v.push_back(ss);


	return v;
}




int main()
{
	std::cout << "Enter the line: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Enter delimiter characters: ";
	std::string w;
	std::getline(std::cin, w);

	if (w.size() == 0)
	{
		w = " ";
	}





	std::vector<std::string> vv = split(s, w);


	for (std::string ss : vv)
	{
		std::cout << ss<<std::endl;
	}



	return 0;
}