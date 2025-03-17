#include <iostream>
using namespace std;
int main() 
{
	int N;
	cin >> N;
	if (N <= 0||N>1000) 
	{
		return 1;
	}
	if (N < 100) 
	{
		cout << N;
	}
	else 
	{
		int x = 99;
		for (int i = 100; i <= N; i++) 
		{
			int a = i / 100;
			int b = (i % 100) / 10;
			int c = (i % 100) % 10;
			if ((a - b) == (b - c)) 
			{
				x++;
			}
		}
		cout << x;
	}
	return 0;
}
