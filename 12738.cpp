#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N; vector<int> hello(N);
    for(int i = 0; i < N ; i++){
        cin >> hello[i];
    }

    int value = 1;
    vector<int> DP;

    for(const auto hi: hello)
    {
        if(DP.size()==0) DP.push_back(hi);

        if(hi>DP.back())
        {
            DP.push_back(hi);
            value = DP.size();
        }
        else
        {
            auto it = lower_bound(DP.begin(),DP.end(),hi);
            *it = hi;
        }
    }
    cout << value;
    return 0;
}
