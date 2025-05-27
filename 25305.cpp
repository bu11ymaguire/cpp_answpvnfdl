#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> cutline;
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        cutline.push(tmp);
    }
    int i=1;
    while(i<m){
        cutline.pop();
        i++;
    }
    cout<<cutline.top();
    return 0;
}
