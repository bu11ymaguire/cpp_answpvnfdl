#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while(N--)
    {
        int M; cin >>M;
        set<long long> s;
        unordered_map<long long,int> um;

        for(int i = 0 ; i < M ; i++)
        {
            long long tmp; cin >> tmp;
            s.insert(tmp);
            um[tmp]++;
        }

        bool not_half = true;

        for(long long A : s)
        {
            if(um[A]>M/2)
            {
                cout << A <<'\n';
                not_half = false;
                break;
            }
        }

        if(not_half) cout << "SYJKGW\n";
    }
    return 0;
}
