#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;




void print(int& n, vector<double>& value)
{
	if (n > value.size())
	{
		cout << "Error. The vector is smaller than the size you entered." << endl;
	}

	for (int i = 0; i < value[n]; ++i)
	{
		cout << value[i]<<'\n';
	}
}

void fibonacci(int& x, int& y, vector<double>& v, int& n)
{
	v.push_back(x);  // v[0]
	v.push_back(y);  // v[1]

	int z = 2; // Уже занесённые варианты (v[0] и v[1])

	for (int i = z; i < n; ++i)
	{
		z = 0;
		z = x + y;
		y = x;
		x = z;
		if (z > 0)
		{
			v.push_back(z);
		}
		else
		{
			cout << "Error. Too much importance. Only"<< i-1<< "values were recorded." << endl;
			break;
		}
	}
}


void swap_v(vector<double>v)
{
	int x, y;
	double temp;
	int a = v.size();
	x = 0; // v[x] первая ячейка
	y = a-1; // v[y] последняя ячейка
	
	a /= 2; //использован int для того, чтобы значение было целым в цикле который меняет значения

	for (int i = 0; i < a; ++i)
	{
		temp = v[x];
		v[x] = v[y];
		v[y] = temp;
	}
}

void swap_r(vector<double>&v)
{
	int x, y;
	double temp;
	int a = v.size();
	x = 0; // v[x] первая ячейка
	y = a - 1; // v[y] последняя ячейка

	a /= 2; //использован int для того, чтобы значение было целым в цикле который меняет значения

	for (int i = 0; i < a; ++i)
	{
		temp = v[x];
		v[x] = v[y];
		v[y] = temp;
	}
}

void swap_string_v(vector<string>v)
{
	int x, y;
	string temp;
	int a = v.size();
	x = 0; // v[x] первая ячейка
	y = a - 1; // v[y] последняя ячейка

	a /= 2; //использован int для того, чтобы значение было целым в цикле который меняет значения

	for (int i = 0; i < a; ++i)
	{
		temp = v[x];
		v[x] = v[y];
		v[y] = temp;
	}
}

void swap_string_r(vector<string>& v)
{
	int x, y;
	string temp;
	int a = v.size();
	x = 0; // v[x] первая ячейка
	y = a - 1; // v[y] последняя ячейка

	a /= 2; //использован int для того, чтобы значение было целым в цикле который меняет значения

	for (int i = 0; i < a; ++i)
	{
		temp = v[x];
		v[x] = v[y];
		v[y] = temp;
	}
}

