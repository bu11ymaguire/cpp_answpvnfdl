#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string word;
	cin >> word;
	string reverse;
	reverse.resize(word.length());
	for (int i = 0; i <= word.length(); i++) 
	{
		reverse[word.length() - i-1] = word[i];
	}
	if (word.compare(reverse) == 0) 
	{
		cout << '0';
	}
	else {
		cout << '1';
	}
	return 0;
}
