#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() 
{
	int a;
	cin >> a;
	
	for (int i = 1; i <= a; i++) 
	{
		for (int j = 1; j<= i - 1; j++) 
		{
			cout << " ";
		}
		for (int k = 1; k <= 2 * a + 1 - 2 * i; k++) 
		{
			cout << "*";
		}
			cout << endl;	
	}
	for (int i = a - 1; i >= 1; i--)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= 2 * a + 1 - 2 * i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
	
