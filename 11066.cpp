#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
//greater()의 차이: 우선순위 큐에서는 minHeap, sort에서는 내림차순
//11066은 이웃끼리 비교
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N; cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        int n; cin >> n; 
        vector<int> hello(n,0);
        for(int j = 0 ; j < n ;j++)
        {
            cin>>hello[j];
        }
        vector<long long> sum(n,0);
        sum[0] = hello[0];
        for(int j = 1; j < n ; j++)
        {
            sum[j] = sum[j-1] + hello[j]; 
        }

        vector<vector<long long>> dp(n,vector<long long>(n,0));
        for(int len = 2; len <=n; len++)
        { 
            //len 합칠 원소의 개수
            for(int i = 0 ; i <=n-len ; i++)
            {
                int j = i + len - 1;
                dp[i][j] = LONG_LONG_MAX;

                for(int k =i;k<j;k++)
                {
                    long long part_sum = sum[j] - (i > 0  ? sum[i-1]:0);
                    long long cost = dp[i][k] + dp[k+1][j] + part_sum;
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        cout<<dp[0][n-1]<<'\n';
    }

    return 0;
}
