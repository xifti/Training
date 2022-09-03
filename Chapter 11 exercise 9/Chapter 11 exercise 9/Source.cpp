#include <iostream>
#include <vector>
#include <ios>
#include <fstream>


// функция программы 1 - шифрует цифры из файла в бинарные данные. (сохроняя зашифрованное в новом текстовоми документе)
// функция программы 2 - дешифрует бинарные данные (цифр) из файла в цифры. (сохроняя расшифрованное в новом текстовоми документе)


std::ifstream checkin_the_file_extension_to_input(std::string& s) //проверка написал ли юзер .txt в конце строки входящей в cin, если нет, то добавляем в конец строки
{
	const std::string TXT = ".txt";

	std::cout << "Enter fail name to open: ";
	std::cin >> s;

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
	std::ifstream ist{ s.c_str(), std::ios_base::binary};
	if (!ist)
	{
		std::cout << "Error file name.";
		exit(-1);
	}

	return ist;
}


std::ofstream checkin_the_file_extension_to_output(std::string& s) //проверка написал ли юзер .txt в конце строки входящей в cin, если нет, то добавляем в конец строки
{
	const std::string TXT = ".txt";

	std::cout << "Enter fail name to save: ";
	std::cin >> s;

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
	std::ofstream ost{ s.c_str(), std::ios_base::binary };
	if (!ost)
	{
		std::cout << "Error, this file name not found.";
		exit(-1);
	}

	return ost;
}



template<class T>
char* as_bytes(T& i)
{
	void* addr = &i;

	return static_cast <char*>(addr);
}




void crypted(std::string& file_name)
{
	std::ifstream ifs = checkin_the_file_extension_to_input(file_name);

	std::ofstream ofs = checkin_the_file_extension_to_output(file_name);

	std::vector<int> v;

	for (int x; ifs.read(as_bytes(x), sizeof(int));)
	{
		v.push_back(x);
    }

	for (int x : v)
	{
		ofs << x<< ' ';
	}

}


void decrypted(std::string& file_name)
{
	std::ifstream ifs = checkin_the_file_extension_to_input(file_name);

	std::ofstream ofs = checkin_the_file_extension_to_output(file_name);

	std::vector<int> v;

	for (int x; ifs>>x;)
	{
		v.push_back(x);
	}

	for (int x : v)
	{
		ofs.write(as_bytes(x), sizeof(int));
	}
}



int main()
{
	std::cout << "What should I do with the file?"<<std::endl
		<<"1     - create a copy in binary format."<<std::endl
		<<"2     - create a decrypted copy in binary format."<<std::endl
		<<"exit  - to exit" << std::endl;
	std::string file_name;
	while (1)
	{
		std::cin >> file_name;
		if (file_name == "1")
		{
			crypted(file_name);
			std::cout << "Done." << std::endl;
			break;
		}
		else if (file_name == "2")
		{
			decrypted(file_name);
			std::cout << "Done." << std::endl;
			break;
		}
		else if (file_name == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Incorrect input, try again." << std::endl;
		}

	}



	return 0;
}