#include <iostream>
#include <string>
#include <vector>



// менят местами слова (последнее становится первым - первое последним и тд)


int main()
{
	std::cout << "Enter line: ";
	std::string s;
	std::getline(std::cin, s);

	std::string revers;
	std::vector<std::string> v;
	for (int i = 0; i<s.size(); ++i)
	{
		if (isalpha(s[i]))
		{
			revers += s[i];
		}
		else if (revers != "")
		{
			v.push_back(revers);
			revers = "";
		}
	}
	v.push_back(revers);

	for (int i = v.size()-1; i >= 0; --i)
	{
		std::cout << v[i] << ' ';
	}


	return 0;
}