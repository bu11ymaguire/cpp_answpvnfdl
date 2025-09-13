#include<bits/stdc++.h>
using namespace std;
const int mode = 10000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int snake, letter;
    unordered_map<int,int> hello;
    cin >> snake >> letter;

    for(int i = 0; i < snake; i ++)
    {
        int from, to;
        cin >> from >> to;
        hello[from] = to;
    }

    for(int i = 0; i < letter ; i++)
    {
        int from, to;
        cin >> from >> to ;
        hello[from] = to;
    }

    vector<int> dist(101,-1);
    dist[1] = 0;

    queue<int> q; 
    q.push(1);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(now==100)
        {
            break;
        }

        for(int i = 1; i <= 6; i++)
        {
            int next = now + i;
            if(next>100)continue;

            if(hello[next]!=0)
            {
                next = hello[next];
            }

            if(dist[next]==-1)
            {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[100];
    
    return 0;
}
