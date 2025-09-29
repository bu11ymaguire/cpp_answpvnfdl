#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; vector<int> input(N+1); vector<int> dp(N+1,1);
    for(int i =1; i <= N ; i++)
    {
        cin >> input[i];
    }

    for(int j=2; j<=N;j++)
    {
        int value = 0;
        for(int i=1;i<j;i++)
        {
            if(input[j]<input[i])
            {
                value = max(value,dp[i]);
            }
        }
        dp[j] = value + 1;
    }
    int result = 0;

    for(int i=1;i<=N;i++)
    {
        result = max(result,dp[i]);
    }

    cout << result;
    return 0;
}
