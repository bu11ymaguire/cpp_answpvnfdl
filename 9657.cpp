#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> dp(1001);
    dp[1]="SK"; dp[2]="CY"; dp[3]="SK";dp[4]="SK";

    for(int i = 5; i <=1000; i++){
        if(dp[i-4]=="CY"||dp[i-3]=="CY"||dp[i-1]=="CY") //이기는 경우의 수가 하나라도 있으면 이긴다!
        {
            dp[i]="SK";
        }
        else
        {
            dp[i]="CY";
        }
    }

    int N; cin >> N;
    cout <<dp[N];

    return 0;
}
