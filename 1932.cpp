#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N; cin>>N;
    vector<vector<long long>> dp(N+1,vector<long long>(N+1,0));
    for(int i=1;i<=N;i++)
    {
        if(i==1)
        {
            cin>>dp[1][1];
        }
        else
        {
            for(int j=1;j<=i;j++)
            {
                int tmp;cin>>tmp;
                if(j==1){dp[i][j]=dp[i-1][j]+tmp;}
                else if(j==i){dp[i][j]=dp[i-1][j-1]+tmp;}
                else
                {
                    dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tmp;
                }
            }
        }
    }

    long long max = 0;
    for(int i=1;i<=N;i++)
    {
        if(max<dp[N][i]) max = dp[N][i];
    }
    cout<<max;
    return 0;
}
