#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> visited(100001,INT_MAX-1);
    int from,to; cin>>from>>to;

    if(from==to){cout<<0;return 0;}
    visited[from] = 0;
    queue<pair<int,int>> now_node;
    now_node.push({from,0});

    while(!now_node.empty())
    {
        
        int node = now_node.front().first;
        int distance = now_node.front().second;
        now_node.pop();

        vector<pair<int,int>> NODE;
        NODE.push_back({node-1,distance+1});
        NODE.push_back({node+1,distance+1});
        NODE.push_back({2*node,distance});
        for(const auto& hello: NODE)
        {
            int next = hello.first;
            
            if(next<0||next>100000) continue;
            if(visited[next]>hello.second)
            {
                visited[next] = hello.second;
                now_node.push(hello);
            }
        }
    }
    cout<<visited[to];
    return 0;
}
