#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
//문제 조건을 잘 좀 읽자: 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node,vertices,start;
    cin>>node>>vertices>>start;
    vector<vector<int>> graph(node+1);
    for(int i=0;i<vertices;i++)
    {
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from); //양방향 그래프
    }

    for(int i=1;i<=node;i++)
    {
        sort(graph[i].begin(),graph[i].end()); //노드가 낮은 번호부터 방문
    }

    vector<bool> visit_BFS(node+1,false);
    vector<bool> visit_DFS(node+1,false);
    stack<int> DFS;
    queue<int> BFS;
    vector<int> DFS_result;
    vector<int> BFS_result;
    DFS.push(start);
    BFS.push(start);

    while(!DFS.empty())
    {
        int now_node = DFS.top();
        DFS.pop();
        
        if(visit_DFS[now_node]){continue;}
        visit_DFS[now_node] = true;
        DFS_result.push_back(now_node);

        for(int i = graph[now_node].size()-1; i >= 0; i--)// 노드가 낮은 번호부터 방문 -> LIFO 특성상 보정 필요!
        {
            int next = graph[now_node][i];
            if(!visit_DFS[next]) {
                DFS.push(next);
            }
        }
    }
    for(const auto hi: DFS_result)
    {cout<<hi<<' ';}cout<<'\n';

    while(!BFS.empty())
    {
        int now_node = BFS.front();
        BFS.pop();

        if(visit_BFS[now_node]){continue;}
        visit_BFS[now_node] =true;
        BFS_result.push_back(now_node);

        for(const auto hello:graph[now_node])
        {
            if(!visit_BFS[hello])
            {
                BFS.push(hello);
            }
        }
    }
    for(const auto hi : BFS_result){cout<<hi<<' ';}
    return 0;
}
