#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> dp(101);
    dp[1]="SK"; dp[2]="CY"; dp[3]="SK";dp[4]="Sk";

    for(int i = 5; i <=100; i++){
        if(dp[i-4]=="CY"||dp[i-3]=="CY"||dp[i-1]=="CY") //상대방을 지게 할 수 있는 경우의 수가 한 개라도 있으면, 그 게임은 이길 수 있다고 간주.
        {
            dp[i]="SK";
        }
        else //이길 수 있는 경우의 수가 하나도 없으면, 패배.
        {
            dp[i]="CY";
        }
    }

    int N; cin >> N;
    cout <<dp[N];

    return 0;
}
