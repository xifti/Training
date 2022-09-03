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

class Date
{
	int y = 0;
	int m = 0;
	int d = 0;
public:
	Date(int y, int m, int d);

	void add_day(int n);

	bool ask(const Date& d);

	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }
};


Date::Date(int z, int x, int c)
{

	y += z;

	m += x;

	d += c;
}

bool Date::ask(const Date& d)
{
	if (d.year() < 1800 || d.year() >2200)
	{
		std::cout << "Error today. Invalid years.\n";
		return false;
	}

	if (d.month() < 1 || d.month() >12)
	{
		std::cout << "Error today. Invalid month.\n";
		return false;
	}

	if (d.day() < 1 || d.day() >31)
	{
		std::cout << "Error today. Invalid day.\n";
		return false;
	}
}

void Date::add_day(int n)
{
	d += n;

	while (true)
	{
		if (d > 31)
		{
			d -= 31;
			++m;
			if (m > 12)
			{
				m = -12;
				++y;
				if (y > 2200)
					std::cout << "Error tomorrow.Invalid years.\n";
				return;
			}
		}
		if (d <= 31)
			break;
	}
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')' << '\n';
}


void f()
{
	Date today(1996, 06, 27);

	if (today.ask(today) == false) { return; }
	std::cout << today<< '\n';

	Date tomorrow = today;
	tomorrow.add_day(1);

	std::cout << tomorrow << '\n';

}

int main()
{
	f();
}