#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> hello(n+1,0);
    hello[1]=1;hello[2]=2;
    
    for(int i=3;i<=n;i++){
        hello[i]=(hello[i-1]+hello[i-2])%10007;
    }
    cout<<hello[n];
    return 0;
}
