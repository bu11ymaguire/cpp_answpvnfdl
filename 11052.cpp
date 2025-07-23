#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
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

    for(int i=1;i<=N;i++)
    {
       for(int j=1;j<=i;j++)
       {
        dp[i] = max(dp[i],dp[i-j]+hello[j]);
       } 
    }
    
    cout<<dp[N];

    return 0;
}
