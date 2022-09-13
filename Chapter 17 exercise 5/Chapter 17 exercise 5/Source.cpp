#include <iostream>

/*
Задание было написать функцию char* findx(const char* s, const char* x) из за чего пришлось использовать const_cast!
Программа считывает строку из консоли, в С стиле, так же считывает слово которое вам нужно найти в строке, после чего производит поиск по ней.
Пришлось сделать удаление \n символа в конце строк, и замену его на \0, чтобы программа работала во всех случаях корректно.
Концом выполнения программы является вывод на экран строки, началом которой является искомое слово (если оно нашлось), и номер символа после которого встречается это слово в строке.
*/


char* findx(const char* s, const char* x)
{
	const char* px = x;
	const char* ps = s;
	while (*s != '\0'){
		bool flag = true;
		if (*s == *x){
			ps = s;
			for (; *px != '\0' && *ps!='\0'; ++px, ++ps) {
				if (*ps != *px){
					flag = false;
					break;
				}
			}
			if (flag == true) {
				return const_cast<char*>(s);
			}
			px = x;
		}
		++s;
	}

	return nullptr;
}


void check_endl(char* s)
{
	std::size_t size_s = std::strlen(s);
	--size_s; // нужен предпоследний символ строки.
	if (s[size_s] == '\n') 
		s[size_s] = '\0'; // заменяем переход на новую строку нультерминатором.
	
}


int main()
{
	char s[302] = "";
	char x[102] = "";
	printf("Enter the sentence in which the word you want to search for (max size 301): ");
	fgets(s, 302, stdin);
	printf("Enter the word you want to search for (max size 101): ");
	fgets(x, 101, stdin);

	check_endl(s);
	check_endl(x);

	char* p=findx(&s[0], &x[0]);
	if (p == nullptr){
		std::cout << "ERROR";
		return 1;
	}

	size_t j = p - s; 

	printf(p);
	std::cout << "The number in the line: " << j;

	return 0;
}