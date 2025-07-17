#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin>>a>>b;
	vector<int> group_a;
	vector<int> group_b;

	for(int i = 0; i<a;i++)
	{
		int input;
		cin>>input;
		group_a.push_back(input);
	}

	for(int i =0;i<b;i++){
		int input;
		cin>>input;
		group_b.push_back(input);
	}

	sort(group_a.begin(),group_a.end());
	sort(group_b.begin(),group_b.end());
	vector<int> result;
	for(int current : group_a)
	{
		if(!binary_search(group_b.begin(),group_b.end(),current))
		{
			result.push_back(current);
		}
	}
	if(result.empty())
	{
		cout<<result.size();
	}else
	{
		cout<<result.size()<<'\n';
		for(int member:result)
		{
			cout<<member<<' ';
		}
	}
	return 0;
}
