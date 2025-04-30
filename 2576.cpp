#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    priority_queue<int,vector<int>,greater<int>> hello;
    int sum = 0;
    int tmp;
    for(int i=0;i<7;i++){
        cin>>tmp;
        if(tmp%2!=0){
            sum+=tmp;
            hello.push(tmp);
        }
    }

    if(hello.empty()){cout<<-1;}
    else{
        cout<<sum<<'\n';
        cout<<hello.top();
    }
    return 0;
}


