#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,m; 
    cin >> N >>m;

    vector<int> dp(m+1,INT_MAX);
    dp[0] = 0;
    vector<int> input(N);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> input[i];
        dp[input[i]] = 1;
    }
    for(const auto& in:input)
    {
        int cash = in;
        for(int i=cash; i<=m;i++)
        {
            if(dp[i-cash] != INT_MAX)
            {
                dp[i] = min(dp[i],dp[i-cash]+1);
            }   
        }
    }
    if(dp[m]==INT_MAX)cout<<-1;
    else cout << dp[m];
    return 0;
}
