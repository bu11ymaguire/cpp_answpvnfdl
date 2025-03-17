#include <iostream>
#include <cmath> //pow()함수를 사용하기 위해서
using namespace std;
int jaritsu(int n) 
{
	int sum = 0;
	int x = n;
	for (int i = 6; i >= 0; i--) 
	{
		sum += x / (int)(pow(10,i)); //pow(a,b)= a^b 데이터 형태는 double -> int 형태로 변환 필요
		x = n % (int)(pow(10, i));
	}
	return sum;
}

int main() 
{
	int a;
	cin >> a;
	int n = 0;
	for (int i = a; i >= 0; i--)
	{
		if (a == i + jaritsu(i))
		{
			n = i;
		}
	}
	cout << n;
	return 0;
}
