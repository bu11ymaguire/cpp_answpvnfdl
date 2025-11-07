#include<bits/stdc++.h>
using namespace std;
//stack 원리 이해의 시간이다.

vector<vector<int>> G;
vector<int> visited;
vector<int> depth;
int cnt = 0;

void DFS(int node,int Depth)
{
    visited[node] = ++cnt;
    depth[node] = Depth; 
    for(int Node:G[node])
    {
        if(visited[Node]==0)
        {
            DFS(Node,Depth+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V,E,S;
    cin >> V >> E >> S;
    G.resize(V+1);
    visited.resize(V+1,0);
    depth.resize(V+1,-1);

    while(E--)
    {
        int from,to;
        cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    for(int i = 1; i <=V; i++)
    {
        if(G[i].size()!=0){
            sort(G[i].begin(),G[i].end(),greater<int>());
        }
    }

    DFS(S,0);

    long long result = 0;
    for(int i = 1; i <=V;i++)
    {
        result += (long long) visited[i] * depth[i];
    }

    cout << result;

    return 0;
}
