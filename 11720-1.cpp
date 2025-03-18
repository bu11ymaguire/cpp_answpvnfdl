//온몸 비틀어서 푼 버전
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	string A;
	cin >> A;
	int Sum = 0;
	for (int i = 0; i < N; i++) 
	{
		Sum += ((int)A[i] - 48);
	}
	cout << Sum;
	return 0;
}
