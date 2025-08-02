#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> hello(10001,0);
    hello[0]=1;
    for(int i=1;i<=10000;i++)
    {
        hello[i]+=hello[i-1];
    }
    for(int i=2;i<=10000;i++)
    {
        hello[i]+=hello[i-2];
    }
    for(int i=3;i<=10000;i++)
    {
        hello[i]+=hello[i-3];
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int tmp;
        cin>>tmp;
        cout<<hello[tmp]<<'\n';
    }
    return 0;
}
