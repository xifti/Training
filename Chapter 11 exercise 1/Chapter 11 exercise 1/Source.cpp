#include <iostream>
#include <fstream>
#include <vector>

void checkin_the_file_extension(std::string& s)
{
	const std::string TXT = ".txt";

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
}

int main()
{
	std::cout << "Enter the name of the file in which you want to change the character case from LARGE to small: ";
	std::string fail_name;
	std::cin >> fail_name;
	checkin_the_file_extension(fail_name);
	std::ifstream ist{ fail_name };
	if (!ist)
	{
		std::cout << "Incorrect file name" << std::endl;
		std::exit(-1);
	}


	std::vector<std::string> new_words;
	char ch;
	std::string word;
	while (!(ist.eof() || ist.fail()))
	{
		ist.get(ch);

		if (isupper(ch))
		{
			ch += 32;
			word += ch;
		}
		else if (ch == ' '|| ist.eof())
		{
			new_words.push_back(word);
			word = "";
		}
		else
		{
			word += ch;
		}
	}

	std::cout << "Enter the name of the file that will contain the changed values: ";
	std::cin >> fail_name;
	checkin_the_file_extension(fail_name);
	std::ofstream ost{ fail_name };


	for (int i = 0; i < new_words.size(); ++i)
	{
		ost << new_words[i] << ' ';
	}

	return 0;
}