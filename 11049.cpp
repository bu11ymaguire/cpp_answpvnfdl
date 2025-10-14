#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> p(N+1,0);
    for(int i =1; i<=N; i++){
        cin >> p[i-1] >> p[i];
    }

    vector<vector<long long>> dp(N+1,vector<long long>(N+1,LLONG_MAX));

    for(int i=1; i<=N; i++)
    {
        dp[i][i] = 0;
    }


    for(int length = 2; length <=N; length++)
    {
        for(int from =1; from<=N-1;from++)
        {
            int to = from + length -1;
            if(to>N)break;
            long long result = LLONG_MAX;
            for(int k = from; k < to; k++)
            {
                result = min(dp[from][k] + dp[k+1][to] + p[from-1] * p[k]  * p[to],result);
            }
            dp[from][to] = result;
        }
    }
    cout << dp[1][N];
    return 0;
}
