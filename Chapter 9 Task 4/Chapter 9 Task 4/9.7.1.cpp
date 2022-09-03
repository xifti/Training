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




enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
	Date(int y, Month m, int d);
	Date();

	void add_day(int n);

	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

private:
	int y;
	Month m;
	int d;
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}


Date::Date(int yy,Month mm, int dd)
   :y{ yy },
	m{ mm },
	d{ dd }
{
}


void Date::add_day(int n)
{
	d += n;

	while (true)
	{
		if (d > 31)
		{
			if (int(m) == 12) 
			{
				++y; 
			}
			d -= 31;
			++m;
		}
		if (d <= 31)
			break;
	}
}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' <<int(d.month()) 
		<< ',' << d.day() << ')' << '\n';
}


void f()
{
	Date today( 1996, Month::jun, 27);

	std::cout << today << '\n';

	Date tomorrow = today;
	tomorrow.add_day(200);
	
	std::cout << tomorrow << '\n';

}

int main()
{
	f();
}