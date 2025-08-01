#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N,m;
    cin>>N>>m;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1));
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%10007;
        }
    }
    cout<<dp[N][m];
    return 0;
}
