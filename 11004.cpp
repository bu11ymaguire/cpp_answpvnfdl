#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,m,tmp;
    cin>>N>>m;

    priority_queue<int,vector<int>,greater<int>> hello;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        hello.push(tmp);
    }

    for(int i=1;i<=N;i++)
    {
        if(i==m){
            cout<<hello.top();
            break;
        }
        hello.pop();
    }

    return 0;
}
