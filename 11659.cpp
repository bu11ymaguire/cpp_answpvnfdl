#include<iostream>
#include<vector>
using namespace std;

int main() 
{
	int a, b;
	cin >> a >> b;
	if (a < 1 || a>100000) 
	{
		return 1;
	}
	if (b < 1 || b>100000) 
	{
		return 1;
	}
	vector<int> X;
	vector<int> Y;
	vector<int> Z;
	int sum = 0;
	for (int i = 0; i < a; i++) 
	{
		int in;
		cin >> in;
		sum += in;
		X.push_back(in);
		Y.push_back(sum);
	}
	for (int j = 0; j < b; j++)
	{
		int q, w;
		cin >> q >> w;
		if (q > w || q > a || q < 1)
		{
			return 1;
		}
		if (w < 1 || w > a)
		{
			return 1;
		}
		if (q == 1) {
			if (q == w) 
			{
				Z.push_back(X[0]);
			}
			else 
			{
				Z.push_back(Y[w - 1]);
			}
		}
		else {
			int part_sum = Y[w - 1] - Y[q - 2];
			Z.push_back(part_sum);
		}
		
	}
	for (int k = 0; k < b; k++) 
	{
		printf("%d\n", Z[k]);
	}
	return 0;
}
	
