#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> giha;
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp<m){giha.push(tmp);}
    }

    while(!giha.empty()){
        cout<<giha.front()<<' ';
        giha.pop();
    }

    return 0;
}
