#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> hello(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> hello[i];
    }

    vector<int> plus_dp(N,1);
    vector<int> minus_dp(N,1);

    for(int i = 1; i <N; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            if(hello[i]>hello[j])
            {
                plus_dp[i] = max(plus_dp[j]+1 , plus_dp[i]);
            }
        }        
    }

    for(int i = N-2; i>=0 ; i--)
    {
        for(int j = N-1; j > i ; j--)
        {
            if(hello[i]>hello[j])
            {
                minus_dp[i] = max(minus_dp[j]+1,minus_dp[i]);
            }
        }
    }

    int result = 1;

    for(int i = 0; i < N; i++)
    {
        result = max(plus_dp[i]+minus_dp[i]-1,result);
    }
    cout << result;
    return 0;
}
