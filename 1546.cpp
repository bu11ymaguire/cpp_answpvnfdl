#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int a;
	cin >> a;
	if (a > 1000 || a <= 0) 
	{
		return 1;
	}
	vector<int> X;
	int b;
	for (int i = 0; i < a; i++) 
	{
		cin >> b;
		if (b > 100 || b < 0) 
		{
			return 1;
		}
		X.push_back(b);
	}
	int max = 0;
	int sum = 0;
	for (int i = 0; i < a; i++) 
	{
		sum += X[i];
		if (X[i] >= max) 
		{
			max = X[i];
		}
	}
	double result = (double)sum * 100 / (a * max);
	cout << result;
	return 0;
}
