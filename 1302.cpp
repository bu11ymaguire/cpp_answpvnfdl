#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<string,int> check;

bool check_string(string &a,string &b) //찾는 값은 가장 많이 팔린 경우(횟수가 같은 경우 사전 순으로 정렬)
{
    if(check[a]!=check[b]){
        return check[a]<=check[b]; //횟수는 기본적으로 오름차순
    }

    return a>=b; // 횟수가 같을떄는 사전의 역순
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp;
    cin>>tmp;
    vector<string> hello;
    string input;
    for(int i=0;i<tmp;i++)
    {
        cin>>input;
        if(check[input]<=0||check[input]>tmp){
            hello.push_back(input);
            check[input]=1;
            continue;
        }
        check[input]++;
    }
    sort(hello.begin(),hello.end(),check_string);
    cout<<hello.back();
    return 0;
}
