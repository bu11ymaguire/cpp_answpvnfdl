#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int,int>> input(N);

    for(int i = 0; i < N ; i++)
    {
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(),input.end());

    vector<int> DP;
    DP.push_back(input[0].second);

    for(int i =1; i < N ; i++)
    {
        if(input[i].second>DP.back()){
            DP.push_back(input[i].second);
        }else
        {
            auto it = lower_bound(DP.begin(),DP.end(),input[i].second);
            *it = input[i].second;
        }
    }

    cout << N - DP.size();
    return 0;
}
