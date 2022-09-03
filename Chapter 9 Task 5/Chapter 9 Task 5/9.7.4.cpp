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
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

class Date 
{
public:
	int day() const;

	Month month() const;

	int year() const;

	bool flag_f() const;
    
	void add_day(int n);

	void add_month(int n);

    void add_year(int n);

	bool true_or_no();

	Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd }, flag_{ 1 } { }

private:
	int y=1800;
	Month m=Month::jan;
	int d=1;
	bool flag_ = true;
};

int Date::day() const { return d; }

Month Date::month() const { return m; }

int Date::year() const { return y; }
bool Date::flag_f() const { return flag_; }



void Date::add_day(int n)
{	
	for (int i = 1; i < n; ++i)
	{
		if (d != 31)
		{
			++d;
		}
		else
		{
			d = 1;
			add_month(1);
		}
	}
}

void Date::add_month(int n)
{
	if ((int)m == 12)
	{
		add_year(1);
	}
	++m;
}


void  Date::add_year(int n)
{
		++y;
		true_or_no();

}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
	if (d.flag_f() != 0)
	{
		return os << '(' << d.year() << ',' << (int)d.month() << ',' << d.day() << ')' << '\n';
	}
}

bool Date::true_or_no()
{
	if (d < 1 || d>31)
	{
		std::cout << "day error.";
		flag_ = false;
		return flag_;
	}

	if (y < 1800 || y>2200)
	{
		std::cout << "year error.";
		flag_ = false;
		return flag_;
	}
}

int main()
{

	Date today{2199,Month::sep,1 };
	today.true_or_no();


	Date tomorrow = today;

	int n;
	std::cin >> n;

	tomorrow.add_day(n);

	std::cout << tomorrow;

	return 0;
}