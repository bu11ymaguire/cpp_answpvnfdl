#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> jump(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> jump[i];
    }

    vector<int> visited(N+1,-1);
    visited[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i =1; i <=jump[now]; i++)
        {
            int next = now + i;
            if(visited[next]==-1)
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

    cout << visited[N];

    return 0;
}
