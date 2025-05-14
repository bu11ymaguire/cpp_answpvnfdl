#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
//1260 풀이과정
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,b,S;
    cin>>N>>b>>S;
    vector<vector<int>> hello(N+1,vector<int>(N+1,0));
    int f,t;
    for(int i=0;i<b;i++)
    {
        cin>>f>>t;
        hello[f][t]=1;
        hello[t][f]=1;
    }
    stack<int> depth_first;
    vector<bool> visited_dfs(N+1, false);
    vector<int> depth_list;

    depth_first.push(S);

    while(!depth_first.empty())
    {
        int current = depth_first.top();
        depth_first.pop();

        if(visited_dfs[current]){continue;}

        visited_dfs[current] = true;
        depth_list.push_back(current);

        for(int i=N;i>0;i--){
            if(hello[current][i]==1&&!(visited_dfs[i])){
                depth_first.push(i);
            }
        }

    }
    for(int i=0;i<depth_list.size();i++){
        cout<<depth_list[i]<<' ';
    }
    cout<<'\n';
    queue<int> BSF_queue;
    vector<int> BSF_list;
    vector<bool> BSF_visited(N+1,false);
    BSF_queue.push(S);
    BSF_visited[S]=true;
    while(!BSF_queue.empty())
    {
        BSF_list.push_back(BSF_queue.front());
        int current_node = BSF_queue.front();
        BSF_queue.pop();
        for(int i=1;i<=N;i++)
        {
            if(hello[current_node][i]==1&&!(BSF_visited[i])){
                BSF_queue.push(i);
                BSF_visited[i]=true;
            }
        }
    }
    for(int i=0;i<BSF_list.size();i++){
        cout<<BSF_list[i]<<' ';
    }
    return 0;
}
