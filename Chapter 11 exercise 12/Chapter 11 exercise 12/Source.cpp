#include <iostream>
#include <string>


// программа считывает из потока ввода целиком линию, после чего выводит эту линию задом наоборот, но не изменяет внесённую линию 
// ('s' так и остается не измененной, мы просто отобразили это значение 's' с конца в начало)



int main()
{
	std::string s;
	std::getline(std::cin, s);


	for (int i = s.size(); i>=0; --i)
	{
		std::cout << s[i];
	}

	std::cout <<std::endl<< s << std::endl;


	return 0;
}