#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int b;
	vector<int> x;
	for (int i = 0; i < 10; i++) 
	{
		cin >> b;
		if (b < 0) {
			return 1;
		}
		x.push_back(b % 42);
	}
	int N = 0;
	for (int a = 0; a < 10; a++) 
	{
		if (x[a] == -1) 
		{

		}
		else 
		{
			N += 1;
			for (int j = a + 1; j < 10; j++) 
			{
				if (x[a] == x[j]) 
				{
					x[j] = -1;
				}
			}
		}
	}
	cout << N;
}
