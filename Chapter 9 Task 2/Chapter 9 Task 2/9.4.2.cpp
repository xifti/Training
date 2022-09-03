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
	int y = 0;
	int m = 0;
	int d = 0;

	bool YEP = true;
	Date(int y, int m, int d);
		                                 //Проверяем корректность даты
										 //и выполняем инициализацию

	void add_day(int n);                 //Увеличиваем объект на n дней
};


std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')' << '\n';
}

Date::Date(int z, int x, int c)
{
	if (z < 1800 ||z>2200)
	{
		std::cout << "Error today. Invalid years.\n";
		YEP = false;
		return;
	}
	y += z;

	if (x < 1 || x>12)
	{
		std::cout << "Error today. Invalid month.\n";
		YEP = false;
		return;
	}
	m += x;

	if ( c< 1 || c>31)
	{
		std::cout << "Error today. Invalid day.\n";
		YEP = false;
		return;
	}
	d += c;
}

void Date::add_day(int n)
{
	if (YEP == false) { return; }
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



void f()
{
	Date today( 1963,5,5 );

	if (today.YEP == false) { return; }
	std::cout << today << '\n';

	Date tomorrow=today;
	tomorrow.add_day(1);

	std::cout << tomorrow << '\n';

}

int main()
{
	f();
}