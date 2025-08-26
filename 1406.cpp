#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> hello;
    string input; cin>>input;
    for(int i = 0; i < input.size();i++)
    {
        hello.push_back(input[i]);
    }

    int N; cin>>N;
    auto cursor = hello.end();
    for(int i = 0; i < N ; i++)
    {
        char command; cin>>command;
        if(command=='L')
        {
            if(cursor==hello.begin())continue;
            cursor--;
        }
        if(command=='D'){
            if(cursor==hello.end())continue;
            cursor++;
        }
        if(command=='B')
        {
            if(cursor==hello.begin())continue;
            cursor--;
            cursor = hello.erase(cursor); //hello.erase(cursor)를 사용하면 cursor가 가리키는 대상이 삭제되기 때문에 cursor가 가리키는 것이 없어지게 된다!
        }
        if(command=='P')
        {
            char tmp; cin>>tmp;
            hello.insert(cursor,tmp); 
        }
    }
    for(const auto& hi:hello){
        cout<<hi;
    }
    return 0;
}
