#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int tmp;
    priority_queue<int,vector<int>> hi;
    queue<int> haha;
    int n =0;
    for(int i=0;i<9;i++){
        cin>>tmp;
        hi.push(tmp);
        haha.push(tmp);
    }

    while(!haha.empty()){
        n++;
        if(haha.front()==hi.top()){
            break;
        }
        haha.pop();
    }
    cout<<hi.top()<<'\n'<<n;
    return 0;
}
