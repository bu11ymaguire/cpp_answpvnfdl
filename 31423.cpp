#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> shcool(N+1);

    for(int i =1; i <= N ; i++)
    {
        cin >> shcool[i];
    }

    vector<vector<int>> G(N+1);
    vector<int> indegree(N+1,0);
    for(int i = 1; i <= N-1; i++)
    {
        int from, to;
        cin >> from >> to;
        G[from].push_back(to);
        indegree[to]++;
    }

    int root = 0;
    
    for(int i =1; i <=N; i++)
    {
        if(indegree[i]==0){
            root = i;
        }
    }

    stack<int> hello;
    hello.push(root);
    vector<int> order;

    while(!hello.empty())
    {
        int now = hello.top();
        hello.pop();
        order.push_back(now);
   
        for(int i=G[now].size()-1;i>=0;i--)
        {
            hello.push(G[now][i]);
        }
    }

    for(const auto& index: order)
    {
        cout << shcool[index]; 
    }

    return 0;
}
