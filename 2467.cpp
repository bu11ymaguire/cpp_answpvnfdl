#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int input;
	cin>>input;
	vector<int> hello_there;
	int L=-1; int R = -1;
	for(int i=0;i<input;i++)
	{
		int current;
		cin>>current;
		if(current<0)
		{
			L=i;
		}else
		{
			R=i;
		}
		hello_there.push_back(current);
	}
	if(L==-1)
	{
		if(input==1){
			cout<<hello_there[0];
		}else{
			cout<<hello_there[0]<<' '<<hello_there[1];
		}
		return 0;
	}
	if(R==-1)
	{
		if(input==1){
			cout<<hello_there[0];
		}else{
			cout<<hello_there[hello_there.size()-2]<<' '<<hello_there[hello_there.size()-1];
		}
		return 0;
	}
	L = 0;
	R = hello_there.size()-1;
	int answer_L = hello_there[L];
	int answer_R = hello_there[R];
	long long sum = LONG_LONG_MAX;
	while(L<R){
		long long current_sum = hello_there[L] + hello_there[R];
		if(abs(sum)>abs(current_sum))
		{
			sum = current_sum;
			answer_L = hello_there[L];
			answer_R = hello_there[R];
		}
		if(current_sum<0)
		{
			L++;
		}else if(current_sum>0)
		{
			R--;
		}else{
			break;
		}
	}
	cout<<answer_L<<' '<<answer_R;
	return 0;
}
