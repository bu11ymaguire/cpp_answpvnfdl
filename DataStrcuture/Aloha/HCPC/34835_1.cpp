//시간초과. 아니 애초에 CPH Helper에서도 '틀렸습니다.'가 떴다.
#include<bits/stdc++.h>
using namespace std;
int N,k;
long long mode = pow(10,9) + 7;

void DFS(int node, bool go, vector<int>& route, vector<bool> &visit, long long &x)
{
    if(node==0)
    {
        route.push_back(0);

        if(go)
        {
            for(int i = 1; i <=k; i++)
            {
                DFS(i,go,route,visit,x);
            }
        }

        else
        {
            x += route.size()% mode;
            while(!route.empty())
            {
                route.pop_back();
            }
            for(int i=0; i <=k; i++)
            {
                visit[i] = false;
            }

        }
    }
    else if(node==N)
    {
        route.push_back(node);
        visit[node] = true;
        for(int i = N - 1; i >= N - k; i--)
        {
            if(visit[i])continue;
            DFS(i,false,route,visit,x);
        }
    }

    else
    {
        if(go)
        {
            route.push_back(node);
            visit[node] = true;
            for(int i = node+1; (i<=N)&&(i <=node+k);i++)
            {
                if(visit[i])continue;
                DFS(i,go,route,visit,x);
            }
        }
        else
        {
            route.push_back(node);
            visit[node] = true;
            for(int i = node-1; (i>=0)&&(i>=node-k);i--)
            {
                if(visit[i])continue;
                DFS(i,go,route,visit,x);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> k;

    vector<int> route;
    vector<bool> visit(N+1,false);

    long long x = 0;
    DFS(0,true,route,visit, x);

    cout << x;

    return 0;
}
