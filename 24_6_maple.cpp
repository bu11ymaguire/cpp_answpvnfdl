#include<bits/stdc++.h>
using namespace std;
//https://project-ps.com/problem/132
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C; 
    cin >> N >> C;
    set<int> hello;
    map<int,int> good;
    int T = 0;

    for(int i = 0; i < N ; i++)
    {
        int tmp; cin >> tmp;
        hello.insert(tmp);
        good[tmp]++;
    }
    
    long long f = 0;

    for(int i = 0; i < N; i++)
    {
        bool insertion = false;
        int j=1;
        for(const auto& hi : hello)
        {
            if(j==hello.size())
            {
                if(hi>f)
                {
                    good[hi]--;
                    if(good[hi]==0)
                    {
                        hello.erase(hi);
                    }
                    break;
                }
            }
            if(hi<=f)
            {
                T++;
                insertion = true;
                good[hi]--;
                if(good[hi]==0)
                {
                    hello.erase(hi);
                }
            }
            if(insertion) break;
            j++;
        }
        f+= C;
    }
    cout << T;
    return 0;
}
