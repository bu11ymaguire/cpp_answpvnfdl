#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> hello(3,vector<int>(N+1,0)); //행렬 입출력을 아직도 제대로 못다루네 걍 레전드다 ㅋㅋㅋㅋㅋㅋ
    for(int x = 1; x <= N; x++){   
        for(int y = 0; y < 3; y++){
            cin >> hello[y][x];
        }
    }

    vector<vector<long long>> dp(3,vector<long long>(N+1,0));
    dp[0][1] = hello[0][1];
    dp[1][1] = INF;
    dp[2][1] = INF;

    for(int i =2; i <=N; i++)
    {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + hello[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + hello[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + hello[2][i];
    }

    long long one = min(dp[1][N],dp[2][N]);
 
    dp[0][1] = INF;
    dp[1][1] = hello[1][1];
    dp[2][1] = INF;

    for(int i =2; i <=N; i++)
    {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + hello[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + hello[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + hello[2][i];
    }

    long long two = min(dp[0][N],dp[2][N]);

    dp[0][1] = INF;
    dp[1][1] = INF;
    dp[2][1] = hello[2][1];

    for(int i =2; i <=N; i++)
    {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + hello[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + hello[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + hello[2][i];
    }

    long long three = min(dp[0][N],dp[1][N]);


    cout << min(one,min(two,three));

    return 0;
}
