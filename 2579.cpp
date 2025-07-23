#include<iostream>
#include<vector>
#include<utility>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<int> hello(N+1,0);
    for(int i=1;i<=N;i++)
    {
        cin>>hello[i];
    }
    vector<int> dp(N+1,0);
    dp[1] = hello[1];
    dp[2] = hello[1] + hello[2];
    for(int i=3;i<=N;i++)
    {
        dp[i] = max(dp[i-3]+hello[i-1]+hello[i],dp[i-2]+hello[i]);
    }
    cout<<dp[N];
    return 0;
}
