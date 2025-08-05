#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    int m=1;

    vector<int> input(N);
    vector<int> dp(N);
    dp[0]=1;

    for(int i=0;i<N;i++)
    {
        cin>>input[i];
        if(input[i]>dp[i-1]) // 새로운 input 값이 기존 계단보다 높으면 기존 계단에 연결해서 사용할 수 있다
        {
            dp[i] = dp[i-1]+1;
        }else{ // 새로운 input값이 기존 계단 높이보다 높지않으면 기존 계단에 연결 X
            dp[i] = input[i];
        }
        m = max(m,dp[i]);
    }

    cout << m;

    return 0;
}
