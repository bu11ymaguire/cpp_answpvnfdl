#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    int N,tmp;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        if(max.empty()||tmp<max.top()){
            max.push(tmp);
        } else if(tmp>=max.top())
        {
            min.push(tmp);
        }

        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        } else if(min.size()>max.size()){
            max.push(min.top());
            min.pop();
        }
        cout<<max.top()<<'\n';
    }
    return 0;
}
