#include <iostream>
#include <vector>
using namespace std;
//m을 '넘지 않는' 선에서
int main() 
{
	int n, m;
	cin >> n >> m;
	if (n < 3 || n>100) 
	{
		return 1;
	}
	if (m < 10 || m>300000) 
	{
		return 1;
	}
	vector<int> card(n);
	for (int i = 0; i < n; i++) 
	{
		int A;
		cin >> A;
		card[i] = A;
	}
	int sum = 0;
	for (int i = 0; i < n - 2; i++) 
	{
		for (int j = i+1;j < n - 1; j++) 
		{
			for(int k = j + 1; k < n; k++) 
			{
				int sam = card[i] + card[j] + card[k];
				if (sam > sum && sam <= m)
				{
					sum = sam;
				}
			}
		}
		
	}
	cout << sum<<endl;
	return 0;
}
