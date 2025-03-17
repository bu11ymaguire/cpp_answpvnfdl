#include <iostream>
#include <vector>
using namespace std;

long long combination(int n, int k) {
	if (k > n - k) k = n - k; // C(n, k) = C(n, n-k)
	long long result = 1;
	for (int i = 0; i < k; ++i) {
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

int main() 
{
	int x;
	cin >> x;
	vector<long long> Z(x);
	for (int i = 0; i < x; i++) 
	{
		int A, B;
		cin >> A >> B;
		Z[i] = combination(B, A);
	}
	for (int i = 0; i < x; i++) 
	{
		cout << Z[i] << endl;
	}
	return 0;
}
