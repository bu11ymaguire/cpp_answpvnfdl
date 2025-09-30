#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int m; cin >> m;
        vector<int> coins(m);
        for(int i = 0; i < m ; i++)
        {
            cin >> coins[i];
        }

        int max_value; cin >> max_value;
        vector<long long> dp(max_value+1,0); dp[0]=1;

        for(const auto& coin : coins)
        {
            for(int i=coin; i<=max_value; i++)
            {
                dp[i] = dp[i] + dp[i-coin];
            }
        }
        cout << dp[max_value] <<'\n';
    }
    return 0;
}
