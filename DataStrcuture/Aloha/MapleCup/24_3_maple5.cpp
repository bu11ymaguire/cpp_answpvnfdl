#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N,m; cin >>N >>m;
    set<pair<int,int>> check;
    vector<pair<int,int>> good;

    int from = 1;
    int gongcha = 1;

    while(good.size()<m)
    {
        for(int i=1;i<=N&&good.size()<m;i++)
        {
            int to = (from + gongcha - 1) % N + 1;
            if (to == from) continue;
            if(check.find({from,to})==check.end()&&check.find({to,from})==check.end())
            {
                check.insert({from,to});
                check.insert({to,from});
                good.push_back({from,to});
            }else{
                continue;
            }
            from = to;
        }
        gongcha++;
    }

    for(const auto& hi : good)
    {
        cout << hi.first <<' ' << hi.second <<'\n';
    }
    return 0;
}
