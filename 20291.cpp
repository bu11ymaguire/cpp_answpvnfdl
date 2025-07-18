#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_set<string> check_duplicated;
	unordered_map<string,int> duplicate;
	priority_queue<string,vector<string>,greater<string>> hello_there;
	int N;
	cin>>N;
	for(int i = 0; i<N; i++)
	{
		string input;
		cin>>input;
		size_t postion = input.find('.');
		string after;
		after = input.substr(postion+1);

		if(check_duplicated.find(after)==check_duplicated.end())
		{
			check_duplicated.insert(after);
			duplicate[after]++;
			hello_there.push(after);
		}else{
			duplicate[after]++;
		}
	}
	while(!hello_there.empty()){
		cout<<hello_there.top()<<' '<<duplicate[hello_there.top()]<<'\n';
		hello_there.pop();
	}
	return 0;
}
