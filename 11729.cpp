#include<iostream>
#include<cmath>
using namespace std;
long long N = 0;
void hanoi(int n, int a, int b, int c) 
{
	if (n == 0) 
	{
	}
	else 
	{
		hanoi(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		hanoi(n - 1, b, a, c);
	}

}

void hano(int n, int a, int b, int c) 
{
	if (n == 0) 
	{

	}
	else 
	{
		hano(n - 1, a, b, c);
		N++;
		hano(n - 1, b, a, c);
	}
}



int main() 
{
	int n;
	cin >> n;
	if (n < 1 || n>20) 
	{
		return 1;
	}
	hano(n, 1, 2, 3);
	printf("%lld\n", N); // cout 대신 빠른 출력이 가능한 printf 사용
	hanoi(n,1,2,3);
	return 0;
}
