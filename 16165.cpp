#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
    int group, problem;
	cin>>group>>problem;
	unordered_map<string,string> member_info;
	unordered_map<string,vector<string>> group_info;
	for(int i=0;i<group;i++)
	{
		string name;int member;
		cin>>name>>member;
		for(int j=0;j<member;j++)
		{
			string current;
			cin>>current;
			member_info[current] = name;
			group_info[name].push_back(current);
		}
	}
	for(int i=0;i<problem;i++)
	{
		string current_string; int problem_case;
		cin>>current_string>>problem_case;
		if(problem_case==0)
		{
			priority_queue<string,vector<string>,greater<string>> output;
			for(string current_member: group_info[current_string]){
				output.push(current_member);
			}
			while(!output.empty())
			{
				cout<<output.top()<<'\n';
				output.pop();
			}
		}else if(problem_case==1){
			cout<<member_info[current_string]<<'\n';
		}
	}

	return 0;
}
