#include<iostream>
using namespace std;
//스펠링 이슈 실화냐
int main() 
{
	int month[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	int mth, day;
	cin >> mth >> day;
	if (mth <= 0 || mth > 12) 
	{
		return 1;
	}
	if (day <= 0 || day >= 32) 
	{
		return 1;
	}
	int total = 0;
	for (int i = 0; i < mth; i++) 
	{
		total += month[i];
	}
	total += day;
	int mts = total % 7;
	switch (mts)
	{
	    case 0:
		cout << "SUN";
		break;
	    case 1:
		cout << "MON";
		break;
		case 2:
		cout << "TUE";
		break;
		case 3:
		cout << "WED";
		break;
		case 4:
		cout << "THU";
		break;
		case 5:
		cout << "FRI";
		break;
		case 6:
		cout << "SAT";
		break;
	default:
		break;
	}
	return 0;
}
