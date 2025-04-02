#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visit(n+1,false);
    visit[1]=true;
    vector<int> parents(n+1,0);
    parents[1]=1;

    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty())
    {
        int a = bfs.front();
        for(int i=0;i<adj[a].size();i++)
        {
            int x = adj[a][i];
            if(!visit[x])
            {
                visit[x]=true;
                parents[x]=a;
                bfs.push(x);
            }
        }
        bfs.pop();
    }

    for(int i=2;i<=n;i++)
    {
        cout<<parents[i]<<'\n';
    }
    return 0;
}
