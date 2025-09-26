#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007; //문제좀 제대로 읽자;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<long long>> hello(N,vector<long long>(5));

    for(int i =0; i <5; i++)
    {
        hello[0][i]=1;
    }

    for(int i =1 ; i < N; i++)
    {
        hello[i][0] = (hello[i-1][1] + hello[i-1][2] + hello[i-1][3] + hello[i-1][4])%MOD;
        hello[i][1] = (hello[i-1][0] + hello[i-1][3] + hello[i-1][4])%MOD;
        hello[i][2] = (hello[i-1][0] + hello[i-1][4])%MOD;
        hello[i][3] = (hello[i-1][0] + hello[i-1][1])%MOD;
        hello[i][4] = (hello[i-1][0] + hello[i-1][1] + hello[i-1][2])%MOD;
    }

    long long result=0; //초기화는 시켜주자;;

    for(const auto& hi : hello[N-1])
    {
        result += hi;
    }

    result %=MOD;
    cout << result;
    return 0;
}
