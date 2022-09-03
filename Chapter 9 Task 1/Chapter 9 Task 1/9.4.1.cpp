
/*

Это задание следует выполнить с каждой из версий класса Date,
перечисленных ниже. Для каждой версии определите объект класса Date с
именем today, инициализированный датой 19 мая 1963 года. Затем определите
объект класса Date с именем tomorrow и присвойте ему значение,
скопировав в него объект today и увеличив его день на единицу с помощью
функции add_day (). Выведите на печать объекты today и tomorrow, используя оператор <<
Проверка корректности даты может быть очень простой. Вы можете не
обращать внимания на наличие високосных лет. Просто не допускайте,
чтобы месяц выходил за пределы диапазона [1,12], а день месяца - за пределы
делы диапазона [1,31]. Проверьте каждую версию хотя бы на одной некорректной
дате, например (2009, 13,-5).

*/


#include <iostream>

struct Date
{
	int y=0; // год
	int m=0; // месяц
	int d=0; // день
	bool YEP = true;
};


std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')'<<'\n';
}

void init_day(Date& dd, int y, int m, int d) // проверяет, является ли (y m d) правильной датой
{                                            // и если является, то инициализирует объект dd
	if (y<1800||y>2200)
	{
		std::cout << "Error today. Invalid years.\n";
		dd.YEP = false;
		return;
	}
	dd.y += y;

	if (m < 1 || m>12)
	{
		std::cout << "Error today. Invalid month.\n";
		dd.YEP = false;
		return;
	}
	dd.m += m;

	if (d < 1 || d>31)
	{
		std::cout << "Error today. Invalid day.\n";
		dd.YEP = false;
		return;
	}
	dd.d += d;
	std::cout << dd;
}

void add_day(Date& dd, int n) // увеличивает объект dd на n дней
{
	if (dd.YEP == false) { return; }
	dd.d += n;

	while (true)
	{
		if (dd.d > 31)
		{
			dd.d -= 31;
			++dd.m;
			if (dd.m > 12)
			{
				dd.m = -12;
				++dd.y;
				if (dd.y > 2200)
					std::cout << "Error tomorrow.Invalid years.\n";
				return;


			}
		}
		if (dd.d <= 31)
			break;
	}
	std::cout << dd;
		
}

void f()
{
	Date today;
	init_day(today, 1963, 05, 19);  // 19 мая 1963г

	Date tomorrow;
	tomorrow = today;
	add_day(tomorrow,1);

}


int main()
{
	f();
}