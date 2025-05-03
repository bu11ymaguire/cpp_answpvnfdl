#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int,vector<int>> A;
    priority_queue<int,vector<int>,greater<int>> B;

    int N,tmp;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        A.push(tmp);
    }

    for(int j=0;j<N;j++){
        cin>>tmp;
        B.push(tmp);
    }

    int sum = 0;
    while(!A.empty()){
        sum+= A.top()*B.top();
        A.pop();
        B.pop();
    }
    cout<<sum;
    return 0;
}
