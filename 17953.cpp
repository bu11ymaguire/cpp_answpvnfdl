#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d,m; cin >> d >> m;
    vector<vector<int>> menu(m+1,vector<int>(d+1,0)); //문제 조건을 좀 잘봐라....
    for(int i = 1; i <= m ; i++)
    {
        for(int j = 1; j <= d ; j++)
        {
            cin >> menu[i][j];
        }
    }

    vector<vector<int>> dp(d+1,vector<int>(m+1,0));
    for(int j = 1; j <= m ; j++)
    {
        dp[1][j] = menu[j][1];
    }

    for(int day = 2; day <=d ; day++)
    {
        for(int now = 1; now <= m; now++)
        {
            for(int j=1; j<= m; j++)
            {
                if(now==j)
                {
                    int half = menu[now][day]/2;
                    int tmp = dp[day-1][j] + half;
                    dp[day][now] = max(dp[day][now],tmp);
                }
                else
                {
                    int tmp = dp[day-1][j] + menu[now][day];
                    dp[day][now] = max(dp[day][now],tmp);
                }
            }  
        }
    }

    int result = 0;
    for(const auto& hi: dp[d])
    {
        result = max(result,hi);
    }

    cout << result;
    return 0;
}
