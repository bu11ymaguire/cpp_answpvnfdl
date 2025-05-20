#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> hello;
    int n,N,tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N;
        if(N==0){
            if(hello.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<hello.top()<<'\n';
                hello.pop();
            }
        }else{
            for(int j=0;j<N;j++){
                cin>>tmp;
                hello.push(tmp);
            }
        }
    }
    return 0;
}
