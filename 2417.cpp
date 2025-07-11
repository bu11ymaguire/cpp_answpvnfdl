#include <iostream>
#include <math.h> //그냥 제곱근 쓰자...

using namespace std;

int main() {
	long long n;
	long long q;
	
	cin >> n;
	
	q = sqrt(n);

	if ( (q*q) < n) {
		++q;
	}

	cout << q;

	return 0;
}
