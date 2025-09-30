#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> hello(N);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> hello[i];
    }

    vector<int> dp; 
    dp.push_back(hello[0]);

    for(int i=1; i < N ; i++)
    {
        if(hello[i]>dp.back())
        {
            dp.push_back(hello[i]);
        }
        else{
            auto idx = lower_bound(dp.begin(),dp.end(),hello[i]);
            *idx = hello[i];
        }
    }

    cout << dp.size();

    return 0;
}
