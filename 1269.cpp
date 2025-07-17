#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<int> hello_there;
	int n,m;
	cin>>n>>m;
	unordered_set<int> group_A;
	unordered_set<int> group_B;

	for(int i = 0; i<n; i++)
	{
		int hi;
		cin>>hi;
		group_A.insert(hi);
	}

	for(int i = 0; i<m;i++)
	{
		int hi;
		cin>>hi;
		group_B.insert(hi);
	}
	int total = 0;
    for(int hi: group_A)
	{
		if(group_B.find(hi)==group_B.end()){
			total++;
		}
	}
    for(int hi:group_B){
		if(group_A.find(hi)==group_A.end()){
			total++;
		}
	}
	cout<<total;

	return 0;
}
