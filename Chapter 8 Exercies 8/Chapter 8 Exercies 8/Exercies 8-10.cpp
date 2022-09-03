#include<iostream>
#include<vector>
#include<algorithm>


using std::vector;
using std::cin;
using std::cout;
using std::endl;


void product_of_numbers(const vector<double>&price, const vector<double>&weight)
{
	double value=0.0;
	if (price.size() == weight.size())
	{
		for (int i = 0; i < price.size(); ++i)
		{
			value = 0;
			value = price[i] * weight[i];
			cout << value << endl;
		}
	}
	else 
		cout << "Error." << endl;
}

void maxv(vector<double>& v)
{
	double value_max = 0.0;
	double value_min = 1.79769e+308;
	double value_mid = 0.0;
	double median = v.size() / 2;
	double value_median = 0.0;
	int median_ = median;

	if (median == median_)
	{
		value_median += 0.01;
	}
	else
	{
		median = (v.size() / 2) + 0.5;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		value_mid += v[i];
		if (v[i] < value_min) { value_min = v[i]; }
		if (v[i] > value_max) { value_max = v[i]; }
	}
	value_mid /= v.size();

	std::sort(v.begin(), v.end());
	if (v[median] != v[median + 1] && v[median] != v[median - 1]) { value_median = v[median]; }

	cout<<'\n' << value_max << " max value in vector" << endl;
	cout << value_min << " min value in vector" << endl;
	cout << value_mid << " mid value in vector" << endl;
	if (median > 0.01) { cout << value_median << "  median in vector" << endl; }
	else { cout << "The median cannot be determined" << endl; }
	cout << "________________________________" << endl;
	
}

int main()
{
	vector<double>price = {5.5 , 12.0 , 7.23 , 100.0 , 2.17};
	vector<double>weight= { 5.0 , 7.2 , 1.0 , 10.0 , 12.5};

	product_of_numbers(price, weight);
	maxv(price);
	maxv(weight);

	return 0;
}