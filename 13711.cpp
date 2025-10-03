#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; vector<int>indexing(N+1,0);

    for(int i = 0; i<N ; i++)
    {
        int tmp; cin >> tmp;
        indexing[tmp] = i;
    }

    vector<int> mid(N);

    for(int i = 0; i < N ; i++)
    {
        int tmp; cin >> tmp;
        mid[i] = indexing[tmp];
    }

    vector<int> finale;
    for(const auto& hi : mid)
    {
        if(finale.size()==0)
        {
            finale.push_back(hi);
        }else
        {
            if(hi > finale.back())
            {
                finale.push_back(hi);
            }else
            {
                auto it = lower_bound(finale.begin(),finale.end(),hi);
                *it = hi;
            }
        }
    }    
    cout << finale.size();    

    return 0;
}
