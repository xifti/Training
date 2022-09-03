#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


// Программа меняет регистр заглавных букв, удаляет все символы ispunct заменяя их пробельными символами (кроме символов " - и ' , но при условии,
// что символы - и ' являются составляющим-символом слова.) так же программа заменяет все (однозначные) сокращения слов из английского языка 
// ( пример: "i'll" меняет на "i will" )


std::ifstream checkin_the_file_extension(std::string& s) //проверка написал ли юзер .txt в конце строки входящей в cin, если нет, то добавляем в конец строки
{
	const std::string TXT = ".txt";

	std::string::size_type it;
	it = s.find(TXT);
	if (it == std::string::npos)
	{
		s += TXT;
	}
	std::ifstream ist{ s };
	if (!ist)
	{
		std::cout << "Error file name.";
		exit(-1);
	}

	return ist;
}



void removing_delimiters(std::string& s)
{
	std::vector<int> counters;
	int count_erase_insert=-1;
	int size_erase_insert = 0;
	std::string word_for_map_using;
	bool flag=true;
	for (int i = 0; i < s.size(); ++i)
	{
		++count_erase_insert;
		if (isupper(s[i]))
		{
			s[i] += 32;
		}

		if (islower(s[i])||s[i]=='\'')
		{
			if (s[i]=='\'' && flag == false) { break; } //если второй раз встречается символ '

			if (s[i] == '\'') { flag = false; }
			word_for_map_using += s[i];
			++size_erase_insert;

			if (counters.size() == 0)
			{
				counters.push_back(count_erase_insert);
			}
		}
	}


	std::map<std::string, std::string> word_abbreviations = { {"i'm","i am"} , {"i'll","i will"} , {"i've","i have"}  , {"you're","you are"}  ,
		{"you'll","you will"}  ,{"you've","you have"}  , {"he'll","he will"}  , {"she'll","she will"}  , {"it'll","it will"}  ,
		{"we're","we are"}  , {"we'll","we will"}  , {"we've","we have"}  , {"they're","they are"}  ,{"they'll","they will"}  ,
		{"they've","they have"}  , {"there'll","there will"}  , {"isn't","is not"}  , {"aren't","are not"}  , {"don't","do not"}  ,
		{"doesn't","does not"}  , {"wasn't","was not"}  ,{"weren't","were not"}  , {"didn't","did not"}  , {"haven't","have not"}  ,
		{"hasn't","has not"}  , {"won't","will not"}  , {"hadn't","had not"}  , {"can't","cannot"}  , {"couldn't","could not"}  ,{"mustn't","must not"} ,
		{"mightn't","might not"}  , {"needn't","need not"}  , {"shouldn't","should not"}  , {"oughtn't","ought not"}  , {"wouldn't","would not"} ,
		{"what's","what is"},{"how's","how is"},{"where's","where is"} };

	auto search = word_abbreviations.find(word_for_map_using);
	if (search != word_abbreviations.end())
	{
		word_for_map_using = search->second;
		s.erase(counters[0], size_erase_insert);
		s.insert(counters[0], word_for_map_using);
	}


	counters.resize(0);
	count_erase_insert = 0;
	if (s[count_erase_insert] == '-')
	{
			counters.push_back(count_erase_insert);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '\'')
		{
				counters.push_back(count_erase_insert);
		}
		++count_erase_insert;
	}
	count_erase_insert = s.size();
	if (count_erase_insert > 1 && s[count_erase_insert-1]=='-')
	{
		--count_erase_insert;
		counters.push_back(count_erase_insert);
	}
	

	if (counters.size() != 0)
	{
		for (int i = counters.size() - 1; 0 <= i; --i) //начинаем удалять с конца, потому что при удалении s.size() меняется
		{
			s.erase(counters[i], 1);
			s.insert(counters[i], " ");
		}
	}
}




int main()
{
	std::cout << "Enter file name: ";
	std::string search;
	std::cin >> search;
	std::ifstream ist = checkin_the_file_extension(search);


	std::string new_line;
	while (!(ist.eof()||ist.bad()))
	{
		std::string word;
		char ch;
		while (ist.get(ch))
		{
			if (std::isspace(ch) || std::ispunct(ch) && ch != '\'' && ch != '-' && ch!='\"') 
			{ 
				new_line += ' ';
				break; 
			}

			word += ch;
		}
		removing_delimiters(word);
		new_line += word;

		if (ch == '\n'||ist.eof())
		{
			new_line += '\n';
			std::cout << new_line;
			new_line = "";
		}
	}

	return 0;
}