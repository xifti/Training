#include <iostream>

// Копирование строки (в С стиле) в строку расположеную в динамической памяти


std::size_t strlen(const char* start)
{
	const char* end = start;
	for (; *end != '\0'; ++end) {
		;
	}
	return end-start;
}


char* strdup_1(const char* s)
{
	std::size_t size=strlen(s); // не используя стандартную библиотеку написали функцию из STL
	size += 1;
	char* ch = new char[size];

	char* p=ch; //создаем еще 1 указатель чтобы не добовлять каунтер.

	for (; *s != '\0'; ++p){
		*p = *s;
		++s;
	}
	*p = *s; //добавляем нультерминатор в конец.

	return ch;
}




int main()
{
	char s[102]="";
	printf("Enter something line (max size 101 char): ");
	fgets(s, 102, stdin);
	char* line = strdup_1(&s[0]);
	
	printf("%s",line);
	delete[] line;

	return 0;
}