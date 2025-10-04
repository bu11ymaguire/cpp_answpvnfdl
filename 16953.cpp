#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long from,to; cin >> from >> to;
    if(from>=to)
    {
        cout << -1;
        return 0;
    }

    queue<pair<long long,int>> q; q.push({from,0});
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        if(now.first==to)
        {
            cout << now.second + 1;
            return 0;
        }
        if(now.first>to)
        {
            continue;
        }
        if(now.first * 2 <= to) q.push({now.first * 2, now.second + 1});
        if(now.first * 10 + 1 <= to) q.push({now.first * 10 + 1, now.second + 1});
    }
    cout << -1;
    return 0;
}
