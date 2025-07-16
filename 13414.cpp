#include<iostream>
#include<string>
#include<unordered_map>
#include<list>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int priority; int trying;
	cin>>priority>>trying;
	list<string> student;
	unordered_map<string,list<string>::iterator> hello;
	for(int i = 0; i<trying; i++)
	{
		string input;
		cin>>input;
		if(hello.find(input)==hello.end()){
			student.push_back(input);
			hello[input] = --student.end();
		}else
		{
			student.erase(hello[input]);
			student.push_back(input);
		}
	}
	int i =0;
	for(string name: student){
		cout<<name;
		i++;
		if(i==priority){
			break;
		}
		cout<<'\n';
	}
	return 0;
}
