#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> jump(N+1);

    for(int i =1; i <= N ; i++)
    {
        cin >> jump[i];
    }

    int from,to; cin >> from >> to;

    vector<int> visited(N+1,-1);
    queue<int> q;
    visited[from] = 0;
    q.push(from);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(now == to)
        {
            cout << visited[to];
            return 0;
        }

        for(int next = now - jump[now]; next >= 1; next -= jump[now])
        {
            if(visited[next] == -1)
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }

        for(int next = now + jump[now]; next <= N; next += jump[now])
        {
            if(visited[next] == -1)
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
    cout << -1;

    return 0;
}
