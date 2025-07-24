#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<int> hello(N);

    for(int i =0; i<N ; i++)
    {
        cin>>hello[i];
    }

    vector<int> dp(N,1);

    for(int i =1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(hello[j]<hello[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
