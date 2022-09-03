#include <iostream>
#include <string>
#include <ios>

//программа преобразует числа (шестнадцатиричные/восмеричные/десятичные) в десятичные


int main()
{
	std::string s;
	std::cin>>s;

	if (s[0]!='0' || s.size()==1)
	{
		std::cout << s<<" (decimal) convert to decimal "<< s;
	}
	else if (s[1] != 'x')
	{
		std::cout << s << " (octal) convert to decimal " << std::stoul(s, nullptr, 8); 
	}
	else
	{
		unsigned int x = std::stoul(s, nullptr, 16);
		std::cout << s << " (hexadecimal) convert to decimal " << x;
	}

	


	return 0;
}