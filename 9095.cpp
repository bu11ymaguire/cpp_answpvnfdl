#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dp(11,0);
    dp[1]=1;dp[2]=2;dp[3]=4;
    for(int i=4;i<=10;i++)
    {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int input;
        cin>>input;
        cout<<dp[input];
        if(i<N){
            cout<<'\n';
        }
    }
    return 0;
}
