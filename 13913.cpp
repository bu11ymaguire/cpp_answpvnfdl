#include<bits/stdc++.h>
using namespace std;

const int arrange = 100001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> visited(arrange,false);
    vector<int> homecoming(arrange,-1);
    int from, to;
    cin >> from >> to;

    queue<int> qqq;
    visited[from] = true;
    qqq.push({from});

    while(!qqq.empty())
    {
        int now = qqq.front();
        qqq.pop();

        int node[] = {now+1,now-1,now*2};
        for(const auto& hi:node)
        {
            if(hi<0||hi>arrange)continue;
            if(visited[hi])continue;
            visited[hi] = true;
            homecoming[hi] = now;
            qqq.push(hi);
        }

        if(visited[to])break;
    }

    stack<int> adebayo;
    int reverse = to;
    while(reverse!=-1)
    {
        adebayo.push(reverse);
        reverse = homecoming[reverse];
    }
    cout << adebayo.size()-1 <<'\n';

    while(!adebayo.empty())
    {
        cout << adebayo.top()<<' ';
        adebayo.pop();
    }
}
