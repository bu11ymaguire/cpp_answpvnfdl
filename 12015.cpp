#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N; vector<int> hello(N);

    for(int i = 0; i < N ; i++)
    {
        cin >> hello[i];
    }

    vector<int> dp; dp.push_back(hello[0]);

    for(int i =1; i < N; i++) //클때는 push, 크지 않을때는 교체.
    {
        if(dp.back()<hello[i]){
            dp.push_back(hello[i]);
        }

        else
        {
            auto iterate = lower_bound(dp.begin(),dp.end(),hello[i]);
            *iterate = hello[i];
        }
    }

    cout << dp.size();


    return 0;
}
